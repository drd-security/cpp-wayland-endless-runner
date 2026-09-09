/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the Health component.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <algorithm>

#include "Health.hpp"

using namespace gfx;
using namespace std;

Health::Health(int healthPoints)
    : healthPoints(clamp(healthPoints, MinHealth, MaxHealth))
{
}

void Health::heal(int amount)
{
    setHealth(healthPoints + amount);
}

void Health::damage(int amount)
{
    setHealth(healthPoints - amount);
}

void Health::setHealth(int newHealth)
{
    int clampedHealth = clamp(newHealth, MinHealth, MaxHealth);

    if (clampedHealth == healthPoints)
        return;

    healthPoints = clampedHealth;
    notifyObservers();
}

int Health::getHealthPoints() const
{
    return healthPoints;
}

void Health::healthBar(Window &window) const
{
    const int barX = 20;
    const int barY = 20;
    const int barWidth = 200;
    const int barHeight = 20;

    const int filledWidth = static_cast<int>((healthPoints / 100.0f) * barWidth);

    window.fillRect(barX, barY, barWidth, barHeight, Color{60, 60, 60, 255});

    Color fillColor{0, 200, 0, 255};

    if (healthPoints <= 30)
        fillColor = Color{220, 40, 40, 255};
    else if (healthPoints <= 50)
        fillColor = Color{230, 180, 0, 255};
    else if (healthPoints <= 70)
        fillColor = Color{51, 51, 255, 255};

    window.fillRect(barX, barY, filledWidth, barHeight, fillColor);
    window.drawRect(barX, barY, barWidth, barHeight, Color{255, 255, 255, 255});
}

void Health::addObserver(HealthObserver &observer)
{
    observers.push_back(&observer);
    observer.onHealthChanged(healthPoints);
}

/** @brief Notifies all observers of the health change. */
void Health::notifyObservers()
{
    for (HealthObserver *observer : observers)
    {
        if (observer != nullptr)
            observer->onHealthChanged(healthPoints);
    }
}
