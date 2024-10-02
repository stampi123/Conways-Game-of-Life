# Conway's Game of Life

## Project Overview

Conway's Game of Life is a cellular automaton game devised by mathematician John Conway. It consists of a grid of cells that evolve through generations based on simple rules. The game serves as a fascinating example of how complex patterns can emerge from simple rules.

### Implementation

This implementation of Conway's Game of Life features:

- **Grid Representation**: A two-dimensional array representing the cells, where each cell can be alive or dead.
- **Game Rules**: 
  - Any live cell with fewer than two live neighbors dies (underpopulation).
  - Any live cell with two or three live neighbors lives on to the next generation.
  - Any live cell with more than three live neighbors dies (overpopulation).
  - Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
  
- **Simulation Loop**: The game runs in a loop, updating the grid based on the defined rules for a specified number of iterations or until a stopping condition is met.
- **User Interaction**: Functionality to initialize the grid with specific patterns and to visualize the state of the grid in each iteration.

### Skills Demonstrated

- **Algorithm Development**: Designed and implemented algorithms to simulate the evolution of the game based on predefined rules.
- **Data Structures**: Utilized appropriate data structures, such as arrays, to manage the state of the game efficiently.
- **Memory Mangagment**: Managed memory for dynamic allocation of simulation grids and optimized buffer swapping for simulation efficiency
- **Programming Proficiency**: Leveraged C for coding and implementing the game logic and optimized the simulation for performancee.

### Future Enhancements

- Implementing a graphical user interface (GUI) for better visualization of the game's evolution.
- Allowing users to save and load specific configurations or patterns.
- Expanding the rules to explore other variations of cellular automata.

