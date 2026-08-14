#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <vector>
#include <string> // Added for file paths

class SudokuBoard {
private:
    std::vector<std::vector<int>> board; 

public:
    SudokuBoard();
    void printBoard() const;
    bool isValidMove(int row, int col, int value) const;
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;

    // --- New File I/O Methods ---
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
};

#endif // SUDOKUBOARD_HPP