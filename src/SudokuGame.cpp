#include "SudokuGame.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <limits>
#include <string>

SudokuGame::SudokuGame() : isRunning(true) {
    // Optionally load a default puzzle here
    // For now, we will just add a few starting numbers for testing
    board.setCell(0, 0, 5);
    board.setCell(0, 1, 3);
    board.setCell(1, 0, 6);
    board.setCell(2, 1, 9);
    board.setCell(2, 2, 8);
}

void SudokuGame::start() {
    std::cout << "Welcome to Sudoku!\n";
    while (isRunning) {
        board.printBoard();
        displayMenu();
        handleInput();
    }
}

void SudokuGame::displayMenu() const {
    std::cout << "\n1) Enter a move\n";
    std::cout << "2) Solve automatically\n";
    std::cout << "3) Load puzzle from file\n";
    std::cout << "4) Save current puzzle to file\n";
    std::cout << "5) Exit\n";
    std::cout << "Choice: ";
}

void SudokuGame::handleInput() {
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }

    std::string filename; // Variable to hold user input for file operations

    switch (choice) {
        case 1:
            enterMove();
            break;
        case 2:
            solveAutomatically();
            break;
        case 3:
            std::cout << "Enter filename to load (e.g., puzzle.txt): ";
            std::cin >> filename;
            if (board.loadFromFile(filename)) {
                std::cout << "Puzzle loaded successfully!\n";
            } else {
                std::cout << "Error: Could not open file '" << filename << "'.\n";
            }
            break;
        case 4:
            std::cout << "Enter filename to save (e.g., my_save.txt): ";
            std::cin >> filename;
            if (board.saveToFile(filename)) {
                std::cout << "Puzzle saved successfully!\n";
            } else {
                std::cout << "Error: Could not save to file '" << filename << "'.\n";
            }
            break;
        case 5:
            isRunning = false;
            std::cout << "Exiting game...\n";
            break;
        default:
            std::cout << "Invalid choice. Please select 1-5.\n";
            break;
    }
}
void SudokuGame::enterMove() {
    int row, col, value;
    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
    std::cin >> row >> col >> value;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter numbers only.\n";
        return;
    }

    // Adjust for 0-indexed internal board representation
    int r = row - 1;
    int c = col - 1;

    // Reject out-of-range input
    if (r < 0 || r > 8 || c < 0 || c > 8 || value < 1 || value > 9) {
        std::cout << "Values must be between 1 and 9.\n";
        return;
    }

    // Check validity of user move
    if (board.isValidMove(r, c, value)) {
        board.setCell(r, c, value);
        std::cout << "Move accepted!\n";
    } else {
        std::cout << "Invalid move! That violates Sudoku constraints.\n";
    }
}

void SudokuGame::solveAutomatically() {
    SudokuSolver solver(&board);
    if (solver.solve()) {
        std::cout << "Puzzle solved!\n";
    } else {
        std::cout << "This puzzle is unsolvable.\n";
    }
}