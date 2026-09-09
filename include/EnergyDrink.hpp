/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * EnergyDrink is an additional pickup feature. It temporarily increases
 * Thomas' movement step distance.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "PickupObstacle.hpp"

class EnergyDrink : public PickupObstacle
{
public:
    EnergyDrink(int x, int y); // Constructor to initialize the EnergyDrink pickup
    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const override;

protected:
    void applyPickupEffect(Player &player) override;

private:
    static constexpr float BoostDuration = 5.0f; // Duration of the speed boost
    static constexpr float SpeedMultiplier = 2.0f; // Multiplier for thomas speed during the boost
    static constexpr int WIDTH = 16;
    static constexpr int HEIGHT = 28;
};
