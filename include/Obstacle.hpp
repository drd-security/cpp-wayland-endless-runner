/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file defines the abstract Obstacle class shared by all obstacles.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "Window.hpp"
#include "Player.hpp"

class Obstacle
{
public:
    Obstacle(int x, int y, int width, int height, gfx::Color color);
    virtual ~Obstacle() = default;

    Obstacle(const Obstacle &) = delete;
    Obstacle &operator=(const Obstacle &) = delete;
    Obstacle(Obstacle &&) = delete;
    Obstacle &operator=(Obstacle &&) = delete;

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    gfx::Color getColor() const;

    /** @brief Draws the obstacle at its position with the given color. */
    virtual void draw(gfx::Window &window, int offsetX, int offsetY, gfx::Color color) const = 0;
    /** @brief Applies the obstacle-specific effect when the player(thomas) collides with it.*/
    virtual bool onCollision(Player &player) = 0;
    /** @brief Moves the obstacle leftward by speed pixels. */
    void move(int speed);
    /** @brief Returns true if the obstacle has gone off the left edge of the screen. */
    bool outOfScreen() const;
    /** @brief Returns true if the obstacle overlaps with the player. */
    bool intersects(const Player &player) const;
    /** @brief Returns true if the obstacle is still active. */
    bool isActive() const;
    /** @brief Deactivates the obstacle, marking it for removal. */
    void deActivate();

protected:
    int x;
    int y;
    int width;
    int height;
    bool active = true;
    gfx::Color color;
};
