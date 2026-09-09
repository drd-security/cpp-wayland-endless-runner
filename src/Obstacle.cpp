/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carré Surfer
 *
 * This file Implement the  super class Obstacle, shared by all
 * obstacles in the Carré Surfer game.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */
#include "Obstacle.hpp"

using namespace gfx;

Obstacle::Obstacle(int x, int y, int width, int height, Color color)
    : x(x), y(y), width(width), height(height), color(color) {}

int Obstacle::getX() const
{
    return x;
}

int Obstacle::getY() const
{
    return y;
}

int Obstacle::getWidth() const
{
    return width;
}

int Obstacle::getHeight() const
{
    return height;
}

Color Obstacle::getColor() const
{
    return color;
}

void Obstacle::move(int speed)
{
    x -= speed;
}

bool Obstacle::outOfScreen() const
{
    return x + width < 0.0f;
}

bool Obstacle::intersects(const Player &player) const
{
    float playerRight = player.getX() + player.getPSize();
    float playerBottom = player.getY() + player.getPSize();
    float playerLeft = player.getX();
    float playerTop = player.getY();
    float obstacleLeft = x;
    float obstacleTop = y;
    float obstacleRight = x + width;
    float obstacleBottom = y + height;
    return obstacleLeft < playerRight && obstacleRight > playerLeft &&
           obstacleTop < playerBottom && obstacleBottom > playerTop;
}

void Obstacle::deActivate()
{
    active = false;
}

bool Obstacle::isActive() const
{
    return active;
}
