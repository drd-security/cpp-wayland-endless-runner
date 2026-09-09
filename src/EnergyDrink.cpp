/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the EnergyDrink pickup.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "EnergyDrink.hpp"

using namespace gfx;

EnergyDrink::EnergyDrink(int x, int y)
    : PickupObstacle(x, y, WIDTH, HEIGHT, Color{255, 80, 80, 255})
{
}

void EnergyDrink::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    const int drawX = x + offsetX;
    const int drawY = y + offsetY;

    window.fillRect(drawX, drawY, width, height, color);
    window.drawRect(drawX, drawY, width, height, Color{255, 255, 255, 255});
    window.fillRect(drawX + 4, drawY - 3, width - 8, 4, Color{230, 230, 230, 255});
    window.drawLine(drawX + 4, drawY + 10, drawX + width - 4, drawY + 10, Color{255, 255, 255, 255});
    window.drawLine(drawX + 6, drawY + 16, drawX + width - 6, drawY + 16, Color{255, 255, 255, 255});
}

void EnergyDrink::applyPickupEffect(Player &player)
{
    player.boostSpeed(BoostDuration, SpeedMultiplier);
}
