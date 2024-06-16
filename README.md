# Not So Super Mario

### Mario Game Simulation Readme

#### Overview
This project implements a command-line simulation of a Mario-like game across multiple levels defined in a grid-based environment. Mario interacts with coins, mushrooms, enemies (Goombas and Koopa Troopas), level bosses, and warp pipes. The game progresses based on random movements and interactions within the grid until Mario either wins by defeating all bosses or loses by losing all lives.

#### Project Structure
- **main.cpp**: Contains the main logic for reading input, initializing the game world, simulating Mario's movements and interactions, and logging the game progress.
- **input.txt**: Sample input file that specifies parameters like number of levels, grid dimensions, initial lives, and distribution percentages of game elements across levels.
- **output.txt**: Generated output file that logs every move Mario makes during the game.
- **README.md**: This readme file providing an overview of the project, instructions for running the code, and any additional information.

#### How to Run
To compile and run the program:

1. **Compile**: Use g++ to compile the `main.cpp` file.
   ```bash
   g++ main.cpp -o mario_game
   ```

2. **Run**: Execute the compiled program with the input file name as a command-line argument.
   ```bash
   ./mario_game input.txt
   ```
   This will generate an `output.txt` file containing the detailed log of the game.

#### Game Simulation Details
- **Initialization**: Reads input from `input.txt` to initialize game parameters and constructs the game world grid for each level.
- **Simulation Loop**: Mario starts at a random position in the first level with power level 0. He moves randomly (UP, DOWN, LEFT, RIGHT) across the grid, interacting with each position based on its contents.
- **Interactions**: Mario interacts with coins (collects them), mushrooms (increases power level), enemies (fights with probabilities), bosses (fights with specific probabilities), and warp pipes (moves to the next level).
- **Logging**: Each interaction is logged into `output.txt`, detailing Mario's current position, power level, action taken, remaining lives and coins, and the next direction he will move.
- **Game End**: The game ends when Mario defeats the boss of the final level and wins or loses all lives.

#### Requirements
- C++ compiler (tested with g++)
- Text editor or IDE (e.g., VSCode) for code editing
- Terminal or command prompt for running compiled executable

#### Additional Notes
- This simulation adheres strictly to the provided specifications and constraints.
- All code is written in compliance with C++ standards and follows the specified coding style guidelines.

#### References
- No external libraries or non-primitive data structures (e.g., vectors) are used, as per project requirements.
