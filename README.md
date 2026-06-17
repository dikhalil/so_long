# So Long

A simple 2D puzzle game built with **MiniLibX** — a student project from [42 Network](https://42.fr). Navigate a map, collect all coins, and find the exit.

## Gameplay

- **WASD** or **Arrow Keys** — move the player
- **ESC** — quit the game
- Collect all **C** (coins) on the map
- Reach **E** (exit) to win
- **1** (wall) blocks your path
- **0** (floor) is walkable

## Building

### Prerequisites

- **MiniLibX** (provided in `/sgoinfre/mlx_linux/`)
- X11 development libraries (`libx11-dev`, `libxext-dev`)

### Compile

```bash
# Point to your MLX installation
make MLX_DIR=/sgoinfre/mlx_linux
```

Or if MLX is available system-wide:

```bash
make
```

### Run

```bash
./so_long maps/map.ber
```

### Clean

```bash
make clean      # remove object files
make fclean     # remove object files + binary
make re         # rebuild from scratch
```

## Map Format

Maps use `.ber` files with these characters:

| Char | Element  |
|------|----------|
| 1    | Wall     |
| 0    | Floor    |
| P    | Player   |
| C    | Collectible (coin) |
| E    | Exit     |

The map must be rectangular, fully enclosed by walls, contain exactly one player and one exit, at least one coin, and have a valid path to all items.

## Project Structure

```
.
├── include/          # Header files
├── libft/            # Custom C library (libft)
├── maps/             # .ber map files
├── src/              # Source code
│   ├── so_long.c     # Entry point and game loop
│   ├── init_map.c    # Map loading and parsing
│   ├── validate_map.c# Map validation
│   ├── flood_fill.c  # Path-finding validation
│   ├── hook.c        # Keyboard and window hooks
│   ├── move.c        # Player movement logic
│   ├── load_img.c    # Texture loading
│   └── exit.c        # Cleanup and error handling
├── textures/         # XPM sprite files
├── Makefile          # Build system
└── README.md
```

## Author

**dikhalil** — 42 Amman
