/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file defines the BoltScooter class, a damaging obstacle.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "DamagingObstacle.hpp"

class BoltScooter : public DamagingObstacle
{
public:
    BoltScooter(int x, int y);  // Constructor to initialize the BoltScooter
    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const override;

protected:
    void applyDamageEffect(Player &player) override;    

private:
    static constexpr int WIDTH = 15;
    static constexpr int HEIGHT = 45;
    static constexpr int DAMAGE = 30;
};
