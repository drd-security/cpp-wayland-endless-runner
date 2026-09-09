/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file defines the DrunkStudent class, a damaging obstacle.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */
#pragma once

#include "DamagingObstacle.hpp"

class DrunkStudent : public DamagingObstacle
{
public:
    DrunkStudent(int x, int y); // Constructor to initialize the DrunkStudent
    void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const override;

protected:
    void applyDamageEffect(Player &player) override;

private:
    static constexpr int MinSize = 20;
    static constexpr int MaxSize = 40;
    static constexpr int DAMAGE = 20;

    /** @brief Generates a random size for the DrunkStudent within the specified range of MinSize and MaxSize. */
    static int randomsize();
    /** @brief Generates a random confusion duration for the DrunkStudent. */
    static int randomConfusionDuration();
    /** @brief internal constructor for creating a DrunkStudent with a specific size. */
    DrunkStudent(int x, int y, int size);
};
