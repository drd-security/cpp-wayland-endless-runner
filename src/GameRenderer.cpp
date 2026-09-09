/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the GameRenderer class.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <algorithm>
#include <cstdint>

#include "GameRenderer.hpp"

using namespace gfx;
using namespace std;

void GameRenderer::draw(Window &window, const Game &game) const
{
    if (game.getState() == GameState::GameOver)
    {
        window.clear(Color{0, 0, 0, 255});
        return;
    }

    const int offsetX = game.getShakeOffsetX();
    const int offsetY = game.getShakeOffsetY();
    const Player &player = game.getPlayer();

    window.clear(applyHealthBrightness(Color{30, 30, 30, 255}));

    for (const auto &obstacle : game.getObstacles())
    {
        obstacle->draw(window, offsetX, offsetY,
                       applyHealthBrightness(obstacle->getColor()));
    }

    player.draw(window, offsetX, offsetY, applyHealthBrightness(player.getColor()));
    player.drawHealthBar(window);
}

void GameRenderer::onHealthChanged(int healthPoints)
{
    healthBrightness = clamp(static_cast<float>(healthPoints) / 100.0f, 0.0f, 1.0f);
}

Color GameRenderer::applyHealthBrightness(const Color &color) const
{
    return Color{static_cast<uint8_t>(color.r * healthBrightness),
                 static_cast<uint8_t>(color.g * healthBrightness),
                 static_cast<uint8_t>(color.b * healthBrightness),
                 255};
}
