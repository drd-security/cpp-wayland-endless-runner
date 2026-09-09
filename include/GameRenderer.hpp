/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Renderer class. It draws the current Game state and observes health changes
 * to update brightness without the game loop computing rendering details.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "Game.hpp"
#include "HealthObserver.hpp"
#include "Window.hpp"

class GameRenderer : public HealthObserver
{
public:
    GameRenderer() = default;

    void draw(gfx::Window &window, const Game &game) const;
    /** @brief Reacts to health changes by adjusting the brightness of the rendering. */
    void onHealthChanged(int healthPoints) override;

private:
    float healthBrightness = 1.0f;

    /** @brief Applies the current health-based brightness to a given color. */
    gfx::Color applyHealthBrightness(const gfx::Color &color) const;
};
