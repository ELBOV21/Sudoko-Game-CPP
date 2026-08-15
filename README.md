# C++ Terminal Sudoku Game

A fully-featured, interactive Sudoku game played directly in the command line. This project is built in C++ and includes features for playing, generating, solving, saving, and loading Sudoku puzzles.

## 🌟 Features

- **Interactive Gameplay:** Play Sudoku directly in your terminal with a clear board visualization.
- **Move Validation:** Built-in constraint checking to ensure user inputs (row, column, value) follow the standard rules of Sudoku.
- **Auto-Solver:** Stuck on a puzzle? Use the automatic solver to find the solution.
- **Puzzle Generator:** Generate brand-new Sudoku puzzles on demand to keep the game fresh.
- **Save & Load Progress:** Easily save your current board state to a text file and load it back up later to resume your game.
- **Clean Architecture:** Code is modularized into distinct classes for the Board, Game, Solver, and Generator.

## 🛠️ Prerequisites & System Requirements

To build and run this project, your system should have the following:

- **C++ Compiler:** A compiler that supports C++17 or later (e.g., GCC/g++, Clang, MSVC).
- **Make:** Required to use the provided `Makefile` for automated building.
- **Operating System:** Cross-platform (Windows, Linux, or macOS) with a standard terminal emulator.

## 🚀 Usage Examples

Once the game is running, you will be greeted with a menu:

```text
Welcome to Sudoku!
... (Board visualization) ...

1) Enter a move
2) Solve automatically
3) Load puzzle from file
4) Save current puzzle to file
5) Generate new puzzle
6) Exit
Choice:
```

### Playing the Game
Select option `1` to enter a move. You will be prompted to enter the row (1-9), column (1-9), and value (1-9) separated by spaces.
```text
Enter row (1-9), column (1-9), and value (1-9): 1 2 5
Move accepted!
```

### Saving/Loading Files
Select option `3` or `4` and provide a filename (e.g., `my_save.txt`) to save or load your board state.

## 🏗️ Build Instructions

This project uses a `Makefile` for a streamlined build process. 

1. **Clone or download** the repository to your local machine.
2. **Open a terminal** and navigate to the project's root directory.
3. **Compile the code** by running:
   ```bash
   make
   ```
   This will compile the source files and create the executable `SudokuGame.exe` in the `bin/` directory.

4. **Run the game** using the Make shortcut:
   ```bash
   make run
   ```
   Alternatively, you can run the executable directly:
   ```bash
   ./bin/SudokuGame.exe
   ```

5. **Clean build files** (optional):
   To remove all compiled object (`.o`) files and the executable, run:
   ```bash
   make clean
   ```
