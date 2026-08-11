#ifndef SUDOKUSOLVER_HPP
#define SUDOKUSOLVER_HPP

#include "SudokuBoard.hpp"

class SudokuSolver {
private:
    SudokuBoard* board; // Pointer to the board to manipulate it directly
    
    // Helper function to find the next empty cell (value 0)
    bool findEmptyCell(int &row, int &col) const;

public:
    // Constructor takes a pointer to the board
    SudokuSolver(SudokuBoard* b);

    // Backtracking method to find a solution
    // Returns true if solved, false if unsolvable
    bool solve(); 
};

#endif // SUDOKUSOLVER_HPP