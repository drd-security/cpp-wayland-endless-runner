/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the application loop.
 *
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <iostream>

#include "windowManager.hpp"

using namespace gfx;
using namespace std;

WindowManager::WindowManager()
    : window("Carre Surfer", WIDTH, HEIGHT),
      game(WIDTH, HEIGHT)
{
    game.healthObserver(renderer);
}

void WindowManager::run()
{
    while (window.isOpen())
    {
        window.pollEvents();
        handleWindowInput();

        if (game.getState() == GameState::Running)
            game.update(window, dt);
        else if (game.getState() == GameState::GameOver)
            handleGameOverInput();

        drawScene();
        window.present();
        window.waitForNextFrame(FPS);
    }
}

void WindowManager::handleWindowInput()
{
    if (window.wasKeyPressed(Key::Escape))
        window.close();
}

void WindowManager::handleGameOverInput()
{
    printGameOverMessage();

    if (window.wasKeyPressed(Key::Space))
        game.reset();
}

void WindowManager::drawScene()
{
    renderer.draw(window, game);
}

void WindowManager::printGameOverMessage()
{
    if (!game.GameOverMessage())
        return;

    cout << " GAME OVER !!! " << endl;
    cout << "Thomas walked for " << game.getElapsedSeconds() << " seconds!" << endl;
    cout << " PRESS SPACE TO START NEW GAME " << endl;
    cout << " PRESS ESC TO QUIT " << endl;
}
