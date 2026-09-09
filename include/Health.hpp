/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Health component owned by Player. It stores Thomas' health points, draws the
 * health bar, and notifies observers when health changes.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include <vector>

#include "HealthObserver.hpp"
#include "Window.hpp"

class Health
{
public:
    explicit Health(int healthPoints);
    ~Health() = default;

    void heal(int amount);
    void damage(int amount);
    void setHealth(int newHealth);

    int getHealthPoints() const;
    void healthBar(gfx::Window &window) const;
    /** @brief Registers an observer to be notified of health changes. */
    void addObserver(HealthObserver &observer);

private:
    static constexpr int MaxHealth = 100;
    static constexpr int MinHealth = 0;

    int healthPoints;
    std::vector<HealthObserver *> observers;

    void notifyObservers();
};
