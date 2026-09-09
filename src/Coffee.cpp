/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the Coffee pickup.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "Coffee.hpp"

using namespace gfx;

Coffee::Coffee(int x, int y)
    : PickupObstacle(x, y, WIDTH, HEIGHT, Color{120, 80, 45, 255})
{
}

void Coffee::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    const int drawX = x + offsetX;
    const int drawY = y + offsetY;

    window.fillRect(drawX, drawY + 6, width, height - 8, color);
    window.drawRect(drawX, drawY + 6, width, height - 8, Color{255, 255, 255, 255});
    window.fillRect(drawX + width, drawY + 10, 6, 8, Color{180, 180, 180, 255});
    window.drawLine(drawX + 5, drawY + 2, drawX + 5, drawY + 5, Color{220, 220, 220, 255});
    window.drawLine(drawX + 12, drawY + 1, drawX + 12, drawY + 5, Color{220, 220, 220, 255});
    window.drawLine(drawX + 19, drawY + 2, drawX + 19, drawY + 5, Color{220, 220, 220, 255});
}

void Coffee::applyPickupEffect(Player &player)
{
    player.clearConfusion();
}
