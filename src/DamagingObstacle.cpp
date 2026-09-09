/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the common collision effect for damaging obstacles.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "DamagingObstacle.hpp"

DamagingObstacle::DamagingObstacle(int x, int y, int width, int height, gfx::Color color)
    : Obstacle(x, y, width, height, color)
{
}

bool DamagingObstacle::onCollision(Player &player)
{
    deActivate(); // Deactivate the obstacle upon collision

    if (player.isInvincible())
        return false;

    applyDamageEffect(player);
    player.makeInvincible(2.0f);

    return true;
}

