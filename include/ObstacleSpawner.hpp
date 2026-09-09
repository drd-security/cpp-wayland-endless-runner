/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * Factory responsible for creating obstacles and pickups features with weighted
 * probabilities.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#pragma once

#include <functional>
#include <memory>
#include <random>
#include <vector>

#include "Obstacle.hpp"

class ObstacleSpawner
{
public:
    ObstacleSpawner(int windowWidth, int windowHeight);

    std::unique_ptr<Obstacle> spawnMainObstacle();
    std::unique_ptr<Obstacle> spawnPickup();

    int nextMainObstacleSpawnInterval(); // Returns the next random interval for spawning a main obstacle.
    int nextPickupSpawnInterval(); // Returns the next random interval for spawning a pickup obstacle.
    int getObstacleSpeed() const;

private:
    struct SpawnRule
    {
        int height;
        std::function<std::unique_ptr<Obstacle>(int, int)> create; // Function to create the obstacle at a given position
    };

    static constexpr int MinMainObstacleSpawnInterval = 30;
    static constexpr int MaxMainObstacleSpawnInterval = 60;
    static constexpr int MinPickupSpawnInterval = 60;
    static constexpr int MaxPickupSpawnInterval = 90;
    static constexpr int ObstacleSpeed = 8;

    int randomInt(int min, int max);
    int randomizeY(int obstacleHeight);

    int windowWidth;
    int windowHeight;
    std::mt19937 rng;
    std::discrete_distribution<int> mainObstacleDistribution;
    std::discrete_distribution<int> pickupDistribution;
    std::vector<SpawnRule> mainObstacleRules; // Rules for spawning main obstacles
    std::vector<SpawnRule> pickupRules; // Rules for spawning pickup obstacles
};
