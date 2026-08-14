#include "SudokuBoard.hpp"
#include <iostream>
#include <fstream>
#include <string>
SudokuBoard::SudokuBoard() : board(9, std::vector<int>(9, 0)) {}

void SudokuBoard::printBoard() const {
    std::cout << "\n-------------------------\n";
    for (int r = 0; r < 9; ++r) {
        std::cout << "| ";
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == 0) {
                std::cout << ". ";
            } else {
                std::cout << board[r][c] << " ";
            }
            if ((c + 1) % 3 == 0) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
        if ((r + 1) % 3 == 0) {
            std::cout << "-------------------------\n";
        }
    }
}

bool SudokuBoard::isValidMove(int row, int col, int value) const {
    // Check if the value is already in the same row or column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == value || board[i][col] == value) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; ++r) {
        for (int c = startCol; c < startCol + 3; ++c) {
            if (board[r][c] == value) {
                return false;
            }
        }
    }

    return true;
}

void SudokuBoard::setCell(int row, int col, int value) {
    board[row][col] = value;
}

int SudokuBoard::getCell(int row, int col) const {
    return board[row][col];
}

// Reads a 9x9 grid of integers from a text file
bool SudokuBoard::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // File could not be opened
    }

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            file >> board[r][c];
        }
    }
    
    file.close();
    return true;
}

// Writes the current 9x9 grid to a text file
bool SudokuBoard::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false; // File could not be created/opened
    }

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            file << board[r][c] << " ";
        }
        file << "\n";
    }

    file.close();
    return true;
}