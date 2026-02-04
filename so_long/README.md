*This project has been created as part of the 42 curriculum by wiboonpr.*

# So_long

## Description
**so_long** is a small 2D game developed in C using the MiniLibX (MLX) graphical library. The goal of the game is to control a character (the Player) who must collect all items (Coins) on the map and escape through the exit.

## Instructions

### Install Minilibx
This project uses MiniLibX for Linux. Before compiling, you must ensure the necessary system dependencies are installed on your machine.
```Bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev zlib1g-dev
```
### Compilation
The project uses a `Makefile` for compilation. To compile the executable, run the following command at the root of the repository:

```bash
make
```
This will generate the `so_long`
executables. 

Other available commands:
```bash
make clean   # Removes object files (.o)
make fclean  # Removes object files and the executable
make re      # Recompiles the project from scratch
```
### Execution
To play the game, run the executable and provide a valid .ber map file as an argument:
```Bash
./so_long ./maps/level1.ber
```
### Game Controls
- W or Arrow Up: Move Up
- A or Arrow Left: Move Left
- S or Arrow Down: Move Down
- D or Arrow Right: Move Right
- ESC or Click X: Close the game
### Map Rules
The map must be a .ber file containing the following characters:
- 1: Wall
- 0: Empty space
- P: Player (Start position)
- C: Collectible (Coin)
- E: Exit

The map must be rectangular, surrounded by walls, and contain a valid path to win.
## Resources
### Tutorial
- [So_long Tutorial](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b)
- [Sample game](https://www.youtube.com/watch?v=tNngHctUoaY)
- [Tutorial Github](https://github.com/mewmewdevart/so_long)
- [MinilibX book](https://42-cursus.gitbook.io/guide/minilibx)
- [MinilibX docs](https://harm-smits.github.io/42docs/libs/minilibx/events.html)
### Tools
- [xev (X event) for create a window and send events to output, this uses to find keysym of X11](https://linux.die.net/man/1/xev)
- [imagemagick uses to convert .png file to .xpm](https://itsfoss.com/install-imagemagick-ubuntu/)



