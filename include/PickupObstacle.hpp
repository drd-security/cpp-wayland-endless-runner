/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Abstract base class for beneficial pickups. A pickup disappears when
 * Thomas collects it, applies its own effect, and does not trigger a screen
 * shake.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "Obstacle.hpp"

class PickupObstacle : public Obstacle
{
public:
    bool onCollision(Player &player) override;

protected:
    /** @brief Constructs a PickupObstacle with the specified position, size, and color. */
    PickupObstacle(int x, int y, int width, int height, gfx::Color color);
    /** @brief Applies the specific pickup effect. */
    virtual void applyPickupEffect(Player &player) = 0;
};
