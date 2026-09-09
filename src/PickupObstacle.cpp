/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the shared collision behaviour for beneficial pickups.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "PickupObstacle.hpp"

PickupObstacle::PickupObstacle(int x, int y, int width, int height, gfx::Color color)
    : Obstacle(x, y, width, height, color)
{
}

bool PickupObstacle::onCollision(Player &player)
{
    deActivate();
    applyPickupEffect(player);
    return false;
}
