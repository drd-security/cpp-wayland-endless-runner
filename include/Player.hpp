/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file defines the Player class, representing Thomas.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include <random>

#include "HealthObserver.hpp"
#include "Health.hpp"
#include "Window.hpp"

class Player
{
public:
    Player(float x, float y);
    ~Player() = default;

    static constexpr int SIZE = 30;
    static constexpr int PSIZE = 30;

    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const;
    void drawHealthBar(gfx::Window &window) const;

    void updatePlayerPos(gfx::Window &window, float dt, int windowWidth, int windowHeight);

    void heal(int amount);
    void damage(int amount);
    void setHealth(int healthPoints);
    int getHealthPoints() const;
    void addHealthObserver(HealthObserver &observer);

    void makeInvincible(float duration);
    bool isInvincible() const;

    void makeConfused(float duration);
    void clearConfusion();
    bool isConfused() const;

    void boostSpeed(float duration, float multiplier);
    bool hasSpeedBoost() const;

    bool makeBlink() const;

    float getX() const { return x; }
    float getY() const { return y; }
    int getSize() const;
    int getPSize() const;
    gfx::Color getColor() const { return color; }

    void resetPlayerPos(float newx, float newy);
    int randomInt(int min, int max);

private:
    static constexpr float BaseStepDistance = 10.0f;
    static constexpr float DefaultSpeedMultiplier = 1.0f;
    static constexpr float StaggerStepInterval = 0.12f;

    float x;
    float y;
    Health health;
    float invincibleTimer = 0.0f;
    float confuseTimer = 0.0f;
    float speedBoostTimer = 0.0f;
    float speedMultiplier = DefaultSpeedMultiplier;

    bool wasLeftPressed = false;
    bool wasRightPressed = false;
    bool wasUpPressed = false;
    bool wasDownPressed = false;

    float drunkTimer = 0.0f;
    float nextStaggerDelay = 2.0f;
    int staggerStepsRemaining = 0;
    int staggerDirection = 0;
    float staggerStepTimer = 0.0f;

    void updateStagger(float dt);
    float getStepDistance() const;
    void updateTimers(float dt);

    std::mt19937 rng;
    gfx::Color color;
};
