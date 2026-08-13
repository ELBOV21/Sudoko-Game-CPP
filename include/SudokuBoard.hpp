#ifndef __SUDOKUBOARD_H__
#define __SUDOKUBOARD_H__
#include <vector>

class SudokuBoard
{
    private:
        std::vector<std::vector<int>> board;

    public:
    // Constructor to initialize an empty 9x9 board
    SudokuBoard();

    // Prints the board in a neat ASCII format
    void printBoard() const;

    // Checks validity of user moves (row/column/3x3 constraints)
    bool isValidMove(int row, int col, int value) const;

    // Sets a value in the puzzle
    void setCell(int row, int col, int value);

    // Retrieves a value from the puzzle (useful for the solver later)
    int getCell(int row, int col) const;


};

#endif // __SUDOKUBOARD_H__