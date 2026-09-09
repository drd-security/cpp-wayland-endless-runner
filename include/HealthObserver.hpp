/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Observer interface used to react to health changes without coupling the
 * health model to the rendering code.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

class HealthObserver
{
public:
    virtual ~HealthObserver() = default;
    virtual void onHealthChanged(int healthPoints) = 0; // react to health change and update rendering brightness accordingly
};
