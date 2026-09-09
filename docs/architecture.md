# Architecture

## Separation of responsibilities

`WindowManager` deals with the platform event loop, `Game` owns gameplay state, and `GameRenderer` handles visual output. This prevents input/rendering details from dominating gameplay classes.

## Polymorphic collision behavior

`Game::checkCollisions()` operates through the abstract `Obstacle` interface. Harmful and beneficial objects share common sequences through `DamagingObstacle` and `PickupObstacle`, while concrete subclasses implement only their specific effects.

## Resource management

`Game` owns active obstacles through `std::vector<std::unique_ptr<Obstacle>>`. Removing an inactive/off-screen element automatically destroys it, keeping ownership and lifetime explicit.

## Observer pattern

`GameRenderer` implements `HealthObserver`. Health changes therefore update rendering feedback without tightly coupling the health model to drawing implementation.

## Runtime cycle

1. Poll window/input events.
2. Update player movement and effect timers.
3. Move obstacles.
4. Check collisions through virtual dispatch.
5. Remove inactive/off-screen objects.
6. Spawn new obstacles/pickups.
7. Update temporary screen-shake state.
8. Render the current scene.
