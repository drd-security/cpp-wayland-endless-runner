/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the Player class.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <algorithm>

#include "Player.hpp"

using namespace gfx;
using namespace std;

Player::Player(float x, float y)
    : x(x), y(y), health(100), rng(random_device{}()), color{255, 255, 255, 255}
{
}

void Player::updateStagger(float dt)
{
    if (staggerStepsRemaining > 0)
    {
        staggerStepTimer -= dt;

        if (staggerStepTimer <= 0.0f)
        {
            y += static_cast<float>(staggerDirection) * BaseStepDistance;
            --staggerStepsRemaining;
            staggerStepTimer = StaggerStepInterval;
        }

        return;
    }

    drunkTimer += dt;

    if (drunkTimer >= nextStaggerDelay)
    {
        staggerDirection = randomInt(0, 1) == 0 ? -1 : 1;
        staggerStepsRemaining = randomInt(1, 5);
        staggerStepTimer = 0.0f;
        drunkTimer = 0.0f;

        // The statement says "every 2 seconds on average".
        // A uniform value between 1 and 3 gives an average of 2 seconds.
        nextStaggerDelay = static_cast<float>(randomInt(1, 3));
    }
}

float Player::getStepDistance() const
{
    return BaseStepDistance * speedMultiplier;
}

void Player::updateTimers(float dt)
{
    if (confuseTimer > 0.0f)
        confuseTimer = max(0.0f, confuseTimer - dt);
    if (invincibleTimer > 0.0f)
        invincibleTimer = max(0.0f, invincibleTimer - dt);
    if (speedBoostTimer > 0.0f)
    {
        speedBoostTimer = max(0.0f, speedBoostTimer - dt);

        if (speedBoostTimer <= 0.0f)
            speedMultiplier = DefaultSpeedMultiplier;
    }
}

void Player::updatePlayerPos(Window &window, float dt, int windowWidth, int windowHeight)
{
    updateTimers(dt);

    const float direction = isConfused() ? -1.0f : 1.0f;
    const float stepDistance = getStepDistance();

    bool isRightDown = window.isKeyDown(Key::Right) || window.isKeyDown(Key::D);
    if (isRightDown && !wasRightPressed)
        x += direction * stepDistance;
    wasRightPressed = isRightDown;

    bool isLeftDown = window.isKeyDown(Key::Left) || window.isKeyDown(Key::A);
    if (isLeftDown && !wasLeftPressed)
        x -= direction * stepDistance;
    wasLeftPressed = isLeftDown;

    bool isUpDown = window.isKeyDown(Key::Up) || window.isKeyDown(Key::W);
    if (isUpDown && !wasUpPressed)
        y -= direction * stepDistance;
    wasUpPressed = isUpDown;

    bool isDownDown = window.isKeyDown(Key::Down) || window.isKeyDown(Key::S);
    if (isDownDown && !wasDownPressed)
        y += direction * stepDistance;
    wasDownPressed = isDownDown;

    updateStagger(dt);

    x = clamp(x, 0.0f, static_cast<float>(windowWidth - PSIZE));
    y = clamp(y, 0.0f, static_cast<float>(windowHeight - PSIZE));
}

void Player::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    if (!makeBlink())
        return;

    window.fillRect(x + offsetX, y + offsetY, PSIZE, PSIZE, color);
}

void Player::drawHealthBar(Window &window) const
{
    health.healthBar(window);
}

void Player::heal(int amount)
{
    health.heal(amount);
}

void Player::damage(int amount)
{
    health.damage(amount);
}

void Player::setHealth(int healthPoints)
{
    health.setHealth(healthPoints);
}

int Player::getHealthPoints() const
{
    return health.getHealthPoints();
}

void Player::addHealthObserver(HealthObserver &observer)
{
    health.addObserver(observer);
}

void Player::makeInvincible(float duration)
{
    invincibleTimer = duration;
}

bool Player::isInvincible() const
{
    return invincibleTimer > 0.0f;
}

void Player::resetPlayerPos(float newx, float newy)
{
    x = newx;
    y = newy;

    invincibleTimer = 0.0f;
    confuseTimer = 0.0f;
    speedBoostTimer = 0.0f;
    speedMultiplier = DefaultSpeedMultiplier;

    wasLeftPressed = false;
    wasRightPressed = false;
    wasUpPressed = false;
    wasDownPressed = false;

    drunkTimer = 0.0f;
    nextStaggerDelay = 2.0f;
    staggerStepsRemaining = 0;
    staggerDirection = 0;
    staggerStepTimer = 0.0f;
}

void Player::makeConfused(float duration)
{
    confuseTimer = duration;
}

void Player::clearConfusion()
{
    confuseTimer = 0.0f;
}

bool Player::isConfused() const
{
    return confuseTimer > 0.0f;
}

void Player::boostSpeed(float duration, float multiplier)
{
    speedBoostTimer = duration;
    speedMultiplier = multiplier;
}

bool Player::hasSpeedBoost() const
{
    return speedBoostTimer > 0.0f;
}

bool Player::makeBlink() const
{
    if (!isInvincible())
        return true;

    return static_cast<int>(invincibleTimer * 10.0f) % 2 == 0;
}

int Player::randomInt(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int Player::getSize() const
{
    return SIZE;
}

int Player::getPSize() const
{
    return PSIZE;
}
