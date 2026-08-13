#include <iostream>
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"

int main() {
    SudokuBoard board;
    // Load a simple predefined puzzle state for testing
    // (A real puzzle would have more numbers, but this is a quick test)
    board.setCell(0, 0, 5);
    board.setCell(0, 1, 3);
    board.setCell(1, 0, 6);
    board.setCell(2, 1, 9);
    board.setCell(2, 2, 8);
    
    std::cout << "--- Initial Unsolved Board ---\n";
    board.printBoard();

    // Create the solver and pass the memory address of our board
    SudokuSolver solver(&board);

    std::cout << "\nSolving...\n";
    
    // Trigger the solver
    if (solver.solve()) {
        std::cout << "\n--- Puzzle Solved! ---\n";
        board.printBoard();
    } else {
        std::cout << "\nUnsolvable puzzle.\n";
    }

    return 0;
}