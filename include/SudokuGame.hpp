#ifndef SUDOKUGAME_HPP
#define SUDOKUGAME_HPP

#include "SudokuBoard.hpp"

class SudokuGame {
private:
    SudokuBoard board;
    bool isRunning;

    void displayMenu() const;
    void handleInput();
    void enterMove();
    void solveAutomatically();

public:
    SudokuGame();
    void start(); // Starts the main game loop
};

#endif // SUDOKUGAME_HPP