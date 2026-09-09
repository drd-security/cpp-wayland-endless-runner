/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file defines the Kebab pickup feature. It restores a small amount of health.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "PickupObstacle.hpp"

class Kebab : public PickupObstacle
{
public:
    Kebab(int x, int y); // Constructor to initialize the Kebab pickup
    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const override;

protected:
    void applyPickupEffect(Player &player) override;

private:
    static constexpr int DIAMETER = 15;
    static constexpr int HealAmount = 10;

    int radius() const;
    int centerX() const;
    int centerY() const;
};
