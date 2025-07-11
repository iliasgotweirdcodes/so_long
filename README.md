# so_long (42 Project)

This repository contains my implementation of the **so_long** project from 42, which introduces basic 2D game programming in C using a simple graphics library.

## Project Overview

**so_long** is a small 2D game where the player must navigate a map, collect all items, and reach the exit. The project teaches fundamentals of graphics, event handling, and game logic in C.

## Key Features

- **2D Map Rendering:** The game map is displayed using the **minilibx (MLX) library**, a graphics toolkit provided by 42. Walls, collectibles, the player, and exits are represented by images or colored tiles.
- **Keyboard Controls:** The player can move up, down, left, or right using keyboard input, with real-time map updates and smooth movement.
- **Collectibles and Exit Logic:** The game only allows access to the exit after all collectibles are gathered, enforcing logical progression and victory conditions.
- **Valid Map Parsing:** Map files (usually `.ber` format) are parsed and validated using custom logic in C, ensuring requirements such as rectangular shape, valid characters, and at least one player, exit, and collectible.
- **Event Handling:** Handles user input and window events (such as closing the window gracefully).
- **Error Handling:** Reports and manages invalid maps, memory errors, and forbidden actions.

## MLX Library Usage

The project utilizes the **minilibx (MLX) library**—a lightweight graphics library provided as part of 42's tools. MLX supports window creation, image rendering, and event management, making it ideal for simple 2D games. Both graphics display and map parsing rely on MLX for efficient and responsive operations.

## How It Works

1. **Map Loading:** Parses a map file (usually `.ber` format), checking for valid structure and characters.
2. **Game Initialization:** Sets up graphics with MLX, loads assets, and places game entities on the map.
3. **Gameplay Loop:** Responds to keyboard events, updates player position, handles collectible pickup, and checks for win/lose conditions.
4. **Resource Management:** Cleans up graphics, memory, and window resources on exit or failure.

## Example Usage

Clone and build the project:

```sh
git clone https://github.com/iliasgotweirdcodes/so_long.git
cd so_long
make
```

Run the game with a map:

```sh
./so_long maps/example.ber
```

## Project Highlights

- **Introduction to Graphics:** Experience with drawing, event loops, and image handling through MLX.
- **Game Logic:** Implementation of movement, collision detection, and victory conditions.
- **File Parsing:** Learn robust map parsing and validation techniques.
- **Event-Driven Programming:** Practice handling asynchronous events and user input.

## References

- [so_long Project Specification (42)](https://github.com/42Paris/subjects/blob/master/so_long.pdf)
- [Minilibx Graphics Library](https://harm-smits.github.io/42docs/libs/minilibx)
- [2D Game Development - Wikipedia](https://en.wikipedia.org/wiki/2D_game)

---

Feel free to explore the code, create your own maps, and experiment with extending the gameplay!
