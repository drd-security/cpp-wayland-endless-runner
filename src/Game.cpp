/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the game state and game rules.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <algorithm>

#include "Game.hpp"

using namespace std;

Game::Game(int windowWidth, int windowHeight)
    : windowWidth(windowWidth),
      windowHeight(windowHeight),
      player((windowWidth - Player::PSIZE) / 16.0f, (windowHeight - Player::PSIZE) / 2.0f),
      spawner(windowWidth, windowHeight),
      rng(random_device{}()),
      mainObstacleSpawnTimer(spawner.nextMainObstacleSpawnInterval()),
      pickupSpawnTimer(spawner.nextPickupSpawnInterval())
{
}

void Game::update(gfx::Window &window, float dt)
{
    if (state != GameState::Running)
        return;

    updateRunning(window, dt);
}

void Game::updateRunning(gfx::Window &window, float dt)
{
    player.updatePlayerPos(window, dt, windowWidth, windowHeight);
    updateObstacles();
    checkCollisions();
    removeInactiveObstacles();
    updateSpawning();
    updateShake(dt);

    elapsedTime += dt;

    if (player.getHealthPoints() <= 0)
        GameOver();
}

void Game::updateObstacles()
{
    for (const auto &obstacle : obstacles)
        obstacle->move(spawner.getObstacleSpeed());
}

void Game::checkCollisions()
{
    for (const auto &obstacle : obstacles)
    {
        if (obstacle->intersects(player) && obstacle->onCollision(player))
            startShake(0.25f);
    }
}

void Game::removeInactiveObstacles()
{
    obstacles.erase(
        remove_if(obstacles.begin(), obstacles.end(),
                  [](const unique_ptr<Obstacle> &obstacle)
                  { return obstacle->outOfScreen() || !obstacle->isActive(); }),
        obstacles.end());
}

void Game::updateSpawning()
{
    --mainObstacleSpawnTimer;
    --pickupSpawnTimer;

    if (mainObstacleSpawnTimer <= 0)
    {
        spawnMainObstacle();
        mainObstacleSpawnTimer = spawner.nextMainObstacleSpawnInterval();
    }

    if (pickupSpawnTimer <= 0)
    {
        spawnPickupObstacle();
        pickupSpawnTimer = spawner.nextPickupSpawnInterval();
    }
}

void Game::updateShake(float dt)
{
    if (shakeTimer <= 0.0f)
        return;

    shakeTimer -= dt;
    shakeOffsetX = randomInt(-4, 4);
    shakeOffsetY = randomInt(-4, 4);

    if (shakeTimer <= 0.0f)
    {
        shakeOffsetX = 0;
        shakeOffsetY = 0;
    }
}

void Game::spawnMainObstacle()
{
    obstacles.push_back(spawner.spawnMainObstacle());
}

void Game::spawnPickupObstacle()
{
    obstacles.push_back(spawner.spawnPickup());
}

void Game::startShake(float duration)
{
    shakeTimer = duration;
}

void Game::reset()
{
    player.setHealth(100);
    player.resetPlayerPos((windowWidth - player.getPSize()) / 16.0f,
                          (windowHeight - player.getPSize()) / 2.0f);
    obstacles.clear();
    mainObstacleSpawnTimer = spawner.nextMainObstacleSpawnInterval();
    pickupSpawnTimer = spawner.nextPickupSpawnInterval();
    elapsedTime = 0.0f;
    gameOverMessagePrinted = false;
    state = GameState::Running;
    startShake(0.0f);
    shakeOffsetX = 0;
    shakeOffsetY = 0;
}

void Game::healthObserver(HealthObserver &observer)
{
    player.addHealthObserver(observer);
}

GameState Game::getState() const
{
    return state;
}

const Player &Game::getPlayer() const
{
    return player;
}

const std::vector<std::unique_ptr<Obstacle>> &Game::getObstacles() const
{
    return obstacles;
}

int Game::getShakeOffsetX() const
{
    return shakeOffsetX;
}

int Game::getShakeOffsetY() const
{
    return shakeOffsetY;
}

int Game::getElapsedSeconds() const
{
    return static_cast<int>(elapsedTime);
}

bool Game::GameOverMessage()
{
    if (state != GameState::GameOver || gameOverMessagePrinted)
        return false;

    gameOverMessagePrinted = true;
    return true;
}

int Game::randomInt(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void Game::GameOver()
{
    state = GameState::GameOver;
}
