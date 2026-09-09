/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * WindowManager owns the window and coordinates the application loop. Game
 * rules are delegated to Game, and drawing is delegated to GameRenderer.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include "Game.hpp"
#include "GameRenderer.hpp"
#include "Window.hpp"

class WindowManager
{
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    WindowManager();
    ~WindowManager() = default;

    void run();

private:
    static constexpr int FPS = 30;
    static constexpr float dt = 1.0f / FPS;

    gfx::Window window;
    Game game;
    GameRenderer renderer;

    void handleWindowInput();
    void handleGameOverInput();
    void drawScene();
    void printGameOverMessage();
};
