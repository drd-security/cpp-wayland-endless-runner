/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This class owns the game state and game rules. WindowManager only owns the
 * window and delegates game updates to this class.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include <memory>
#include <random>
#include <vector>

#include "GameState.hpp"
#include "HealthObserver.hpp"
#include "Obstacle.hpp"
#include "ObstacleSpawner.hpp"
#include "Player.hpp"
#include "Window.hpp"

class Game
{
public:
    Game(int windowWidth, int windowHeight);
    ~Game() = default;

    /** @brief Updates the game state based on the elapsed time and player input. */
    void update(gfx::Window &window, float dt);
    /** @brief Resets the game state to its initial conditions. */
    void reset();
    /** @brief healthObserver to observe health changes. */
    void healthObserver(HealthObserver &observer);

    const Player &getPlayer() const; // Returns a reference to the player object.
    const std::vector<std::unique_ptr<Obstacle>> &getObstacles() const;
    GameState getState() const;    // Returns the current state of the game (Running or GameOver).
    int getShakeOffsetX() const;   // Returns the current horizontal shake offset for screen shake effect.
    int getShakeOffsetY() const;   // Returns the current vertical shake offset for screen shake effect.
    int getElapsedSeconds() const; // Returns the elapsed time in seconds.

    bool GameOverMessage(); // Returns true if the game over message should be printed, false otherwise.

private:
    int windowWidth;
    int windowHeight;
    Player player;
    std::vector<std::unique_ptr<Obstacle>> obstacles;
    ObstacleSpawner spawner;
    GameState state = GameState::Running;
    std::mt19937 rng;

    int mainObstacleSpawnTimer;
    int pickupSpawnTimer;
    float elapsedTime = 0.0f;
    bool gameOverMessagePrinted = false;
    float shakeTimer = 0.0f;
    int shakeOffsetX = 0;
    int shakeOffsetY = 0;

    void updateRunning(gfx::Window &window, float dt);
    void updateObstacles();
    void updateSpawning();
    void updateShake(float dt);
    void checkCollisions();
    void removeInactiveObstacles(); // Removes obstacles that are no longer active (e.g., off-screen or collected).
    void spawnMainObstacle();   // Spawns a new main obstacle in the game.
    void spawnPickupObstacle();     // Spawns a new pickup item in the game.
    void startShake(float duration);
    int randomInt(int min, int max);
    void GameOver();
};
