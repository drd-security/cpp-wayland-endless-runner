/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Coffee is an additional pickup feature. It immediately cancels the
 * reversed controls caused by a collision with another drunk student.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "PickupObstacle.hpp"

class Coffee : public PickupObstacle
{
public:
    Coffee(int x, int y); // Constructor to initialize the Coffee pickup
    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const override;

protected:
    void applyPickupEffect(Player &player) override;

private:
    static constexpr int WIDTH = 24;
    static constexpr int HEIGHT = 24;
};
