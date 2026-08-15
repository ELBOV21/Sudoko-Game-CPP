#include "SudokuGenerator.hpp"
#include "SudokuSolver.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void SudokuGenerator::generate(SudokuBoard& board, int numClues) {
    //1. Create the board Completely Empty
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            board.setCell(i, j, 0);
        }
    }
    //2. Create a randomized seed
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for(int i = 0; i < 9; ++i) {
        board.setCell(0, i, numbers[i]);
    }
    //3. Use the SudokuSolver to fill the board completely
    SudokuSolver solver(&board);
    solver.solve();

    //4. Remove cells to create the puzzle
    int removed = 0;
    std::default_random_engine engine(seed);
    std::uniform_int_distribution<int> dist(0, 8);

    while(removed < (81 - numClues)) {
        int row = dist(engine);
        int col = dist(engine);
        if(board.getCell(row, col) != 0) {
            board.setCell(row, col, 0);
            ++removed;
        }
    }

}