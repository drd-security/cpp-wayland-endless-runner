/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the Kebab pickup.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "Kebab.hpp"

using namespace gfx;

Kebab::Kebab(int x, int y)
    : PickupObstacle(x, y, DIAMETER, DIAMETER, Color{255, 220, 0, 255})
{
}

void Kebab::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    window.fillCircle(centerX() + offsetX, centerY() + offsetY, radius(), color);
}

void Kebab::applyPickupEffect(Player &player)
{
    player.heal(HealAmount);
}

int Kebab::radius() const
{
    return DIAMETER / 2;
}

int Kebab::centerX() const
{
    return x + radius();
}

int Kebab::centerY() const
{
    return y + radius();
}
