/**
 * INFO0004 - Object-oriented programming projects
 * Project 2025-2026 Carre Surfer
 *
 * This file implements the ObstacleSpawner factory.
 * 
 * @author: DONKENG NDIA Dave Ronic
 * @version: 2.0
 */

#include <algorithm>

#include "BoltScooter.hpp"
#include "Coffee.hpp"
#include "DrunkStudent.hpp"
#include "EnergyDrink.hpp"
#include "Garbage.hpp"
#include "Kebab.hpp"
#include "ObstacleSpawner.hpp"

using namespace std;

ObstacleSpawner::ObstacleSpawner(int windowWidth, int windowHeight)
    : windowWidth(windowWidth),
      windowHeight(windowHeight),
      rng(random_device{}()),
      mainObstacleDistribution{20, 30, 10, 40},
      pickupDistribution{50, 50},
      mainObstacleRules{
          SpawnRule{15, [](int x, int y) { return make_unique<Kebab>(x, y); }},
          SpawnRule{45, [](int x, int y) { return make_unique<Garbage>(x, y); }},
          SpawnRule{45, [](int x, int y) { return make_unique<BoltScooter>(x, y); }},
          SpawnRule{40, [](int x, int y) { return make_unique<DrunkStudent>(x, y); }}},
      pickupRules{
          SpawnRule{24, [](int x, int y) { return make_unique<Coffee>(x, y); }},
          SpawnRule{28, [](int x, int y) { return make_unique<EnergyDrink>(x, y); }}}
{
}

unique_ptr<Obstacle> ObstacleSpawner::spawnMainObstacle()
{
    int index = mainObstacleDistribution(rng);
    const SpawnRule &rule = mainObstacleRules.at(static_cast<size_t>(index));
    return rule.create(windowWidth, randomizeY(rule.height));
}

unique_ptr<Obstacle> ObstacleSpawner::spawnPickup()
{
    int index = pickupDistribution(rng);
    const SpawnRule &rule = pickupRules.at(static_cast<size_t>(index));
    return rule.create(windowWidth, randomizeY(rule.height));
}

int ObstacleSpawner::nextMainObstacleSpawnInterval()
{
    return randomInt(MinMainObstacleSpawnInterval, MaxMainObstacleSpawnInterval);
}

int ObstacleSpawner::nextPickupSpawnInterval()
{
    return randomInt(MinPickupSpawnInterval, MaxPickupSpawnInterval);
}

int ObstacleSpawner::getObstacleSpeed() const
{
    return ObstacleSpeed;
}

int ObstacleSpawner::randomizeY(int obstacleHeight)
{
    int maxY = max(0, windowHeight - obstacleHeight);
    return randomInt(0, maxY);
}

int ObstacleSpawner::randomInt(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
