/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the BoltScooter class.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include "BoltScooter.hpp"

using namespace gfx;

BoltScooter::BoltScooter(int x, int y)
    : DamagingObstacle(x, y, WIDTH, HEIGHT, Color{0, 200, 80, 255})
{
}

void BoltScooter::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    window.fillRect(x + offsetX, y + offsetY, width, height, color);
}

void BoltScooter::applyDamageEffect(Player &player)
{
    player.damage(DAMAGE);
}
