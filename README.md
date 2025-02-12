# Werewolf

## Overview

Werewolf is a simple C++ text-based adventure game where the player explores a maze-like map, collects items, and attempts to defeat a werewolf. The player can move around the map, look for items, take items into their inventory, and use items to overcome obstacles or attack the werewolf. The goal is to either defeat the werewolf or achieve another win condition (to be fully implemented).

This project was a collaboration between Christian Davis, Irvin Tancioco, and [Your Name], based on an exercise from Professor Morag of CCSF. [Your Name] was responsible for completing the functions for file persistence, player interactivity, werewolf AI, and werewolf teleportation functionality.

## How to Compile and Run the Game

### Prerequisites

*   A C++ compiler (e.g., g++)
*   A text editor

### Compilation

1.  Save all the source code files (`main.cpp`, `interactionFunctions.cpp`, `mapFunctions.cpp`, `playerFunctions.cpp`, `screenFunctions.cpp`, `utilityFunctions.cpp`, `werewolfFunctions.cpp`) in the same directory.

2.  Open a terminal or command prompt and navigate to that directory.

3.  Compile the code using the following command:

    ```bash
    g++ main.cpp -o werewolf
    ```

    This will create an executable file named `werewolf` (or `werewolf.exe` on Windows).

### Running the Game

1.  Ensure that the `gameSlot0.txt` file (containing the map and initial game state) is in the *same directory* as the `werewolf` executable. The game expects to find this file in order to load the initial map.

2.  Run the game using the following command:

    ```bash
    ./werewolf
    ```

    (or `werewolf.exe` on Windows)

### gameSlot0.txt File Format
The file must contain the map dimensions, initial player/werewolf positions, map data and the initial player health.
The map data has to be packed without any unnecessary characters such as spaces or line feeds.
It is UTF-8 text file.

### Controls

*   `w`: Move up.
*   `s`: Move down.
*   `a`: Move left.
*   `d`: Move right.
*   `l`: Look (examine the square in front of you).
*   `t`: Take (pick up an item from the square in front of you).
*   `u`: Use (use an item from your inventory). You will be prompted to enter the item to use.
*   `Q`: Quit the game.
*   `L`: Load a saved game.
*   `S`: Save the current game.
*   `h`: Display help/instructions.

### Gameplay

The game is turn-based. Each time you enter a command, the player performs an action, and then the werewolf (if alive and not stunned) takes its turn. The goal is to explore the map, collect items to survive, and ultimately defeat the werewolf.

**Win Condition:** The player wins the game by reducing the werewolf's health to 0.

**Losing Condition:** The player loses the game if the werewolf reduces the player's health to 0.

### Map Symbols

*   `#`: Wall
*   ` `: Empty space
*   `O`: Chasm
*   `k`: Key
*   `@`: Lock
*   `=`: Plank
*   `&`: Rope
*   `+`: Health
*   `.`: Pebble
*   `Y`: Slingshot
*   `W`: Werewolf

### Additional Notes

*   The `gameSlot0.txt` file stores the initial state of the game. You can modify this file to change the map layout, item placement, and starting positions.
*   The werewolf moves towards the player each turn, unless stunned.
*   If the werewolf catches the player, the player will take damage.
*   The player can use items to overcome obstacles (e.g., use a plank to cross a chasm) or attack the werewolf (e.g., use a slingshot to shoot pebbles).