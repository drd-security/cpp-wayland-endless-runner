/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the Garbage class.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "Garbage.hpp"

using namespace gfx;

Garbage::Garbage(int x, int y)
    : DamagingObstacle(x, y, WIDTH, HEIGHT, Color{130, 130, 130, 255})
{
}

void Garbage::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    window.fillRect(x + offsetX, y + offsetY, width, height, color);
}

void Garbage::applyDamageEffect(Player &player)
{
    player.damage(DAMAGE);
}
