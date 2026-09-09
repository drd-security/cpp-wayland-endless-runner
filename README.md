# Carré Surfer — C++ Wayland Endless Runner

A small C++20 endless-runner game built directly on Wayland, designed around explicit object-oriented responsibilities, polymorphic obstacles/pickups, RAII ownership, event handling, collision effects, and observer-based health feedback.

## Gameplay

The player moves inside the window while objects scroll from right to left. Harmful obstacles reduce health and can apply temporary effects, while pickups restore or modify the player's state.

### Obstacles and pickups

```text
Obstacle
├── DamagingObstacle
│   ├── Garbage
│   ├── BoltScooter
│   └── DrunkStudent
└── PickupObstacle
    ├── Kebab
    ├── Coffee
    └── EnergyDrink
```

- Garbage: damage.
- Bolt scooter: heavier damage.
- Drunk student: damage + temporarily reversed controls.
- Kebab: healing.
- Coffee: clears the confusion/reversed-control effect.
- Energy drink: temporary movement-speed boost.

## Architecture

| Component | Responsibility |
|---|---|
| `WindowManager` | Owns the window and coordinates the main loop/events. |
| `Game` | Owns game state, player, obstacles, timers, collision logic, spawning, and restart state. |
| `GameRenderer` | Draws the scene and observes health changes for brightness feedback. |
| `Player` | Encapsulates position, health, invincibility, confusion, staggering, and speed-boost timers. |
| `ObstacleSpawner` | Creates obstacle/pickup objects using weighted rules. |
| `Obstacle` hierarchy | Encapsulates drawing and collision behavior through dynamic dispatch. |
| `Health` | Tracks health and notifies observers. |

Active obstacles are owned by `std::unique_ptr` inside a vector, so lifetime is explicit and no manual `new/delete` is required.

## Build

Linux/Wayland dependencies include a C++20 compiler, Wayland client development files, `wayland-scanner`, Wayland protocols, and xkbcommon.

```bash
make
./game
```

## Controls

- Arrow keys / WASD: move.
- Space: restart after game over.
- Escape: exit.

## Academic context and contribution

Two-person OOP project. I completed the majority of the implementation/integration work; my teammate also contributed meaningfully. The architecture was intentionally designed so behavior varies through polymorphism rather than large type switches.

## Portfolio cleanup

The original PDF/LaTeX report and submission-specific material are excluded. The useful architecture explanation has been incorporated into this English README and the docs directory.

## Publication status

See [NOTICE.md](NOTICE.md).
