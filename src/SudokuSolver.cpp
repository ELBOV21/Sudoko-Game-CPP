#include "SudokuSolver.hpp"

// Initialize with the board pointer
SudokuSolver::SudokuSolver(SudokuBoard* b) : board(b) {}

// Scans the board from top-left to bottom-right to find a 0
bool SudokuSolver::findEmptyCell(int &row, int &col) const {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board->getCell(row, col) == 0) {
                return true; // Empty cell found
            }
        }
    }
    return false; // No empty cells left (puzzle solved)
}

// The core recursive backtracking algorithm
bool SudokuSolver::solve() {
    int row, col;

    // Base case: If there are no empty cells, the board is solved!
    if (!findEmptyCell(row, col)) {
        return true;
    }

    // Try placing numbers 1 through 9 in the empty cell
    for (int num = 1; num <= 9; ++num) {
        // Check if placing 'num' here violates Sudoku rules
        if (board->isValidMove(row, col, num)) {
            
            // Make a tentative assignment
            board->setCell(row, col, num);

            // Recursively attempt to solve the rest of the board
            if (solve()) {
                return true;
            }

            // If solve() returned false, this path is a dead end.
            // Backtrack: Undo the assignment and try the next number.
            board->setCell(row, col, 0);
        }
    }

    // If no number 1-9 works in this cell, the puzzle is unsolvable 
    // from the current state. Trigger backtracking in the previous call.
    return false;
}