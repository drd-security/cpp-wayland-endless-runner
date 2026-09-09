/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Abstract obstacle for obstacles whose collision damages Thomas
 * and may apply an additional effect.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 *
 */

#pragma once

#include "Obstacle.hpp"

class DamagingObstacle : public Obstacle
{
public:
    bool onCollision(Player &player) override;

protected:
    /** @brief Constructs a DamagingObstacle with the specified position, size, and color.*/
    DamagingObstacle(int x, int y, int width, int height, gfx::Color color);
    /** @brief Applies the specific damage effect. */
    virtual void applyDamageEffect(Player &player) = 0;
};
