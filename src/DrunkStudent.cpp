/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the DrunkStudent class.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <random>

#include "DrunkStudent.hpp"

using namespace gfx;
using namespace std;

DrunkStudent::DrunkStudent(int x, int y)
    : DrunkStudent(x, y, randomsize())
{
}

DrunkStudent::DrunkStudent(int x, int y, int size)
    : DamagingObstacle(x, y, size, size, Color{102, 102, 255, 255})
{
}

void DrunkStudent::draw(Window &window, int offsetX, int offsetY, Color color) const
{
    window.fillRect(x + offsetX, y + offsetY, width, height, color);
}

void DrunkStudent::applyDamageEffect(Player &player)
{
    player.damage(DAMAGE);
    player.makeConfused(static_cast<float>(randomConfusionDuration()));
}

int DrunkStudent::randomsize()
{
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(MinSize, MaxSize);
    return dist(rng);
}

int DrunkStudent::randomConfusionDuration()
{
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 5);
    return dist(rng);
}
