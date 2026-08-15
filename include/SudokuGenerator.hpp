#ifndef __SUDOKOGENERATOR_H__
#define __SUDOKOGENERATOR_H__

#include "SudokuBoard.hpp"
class SudokuGenerator {
public:
    void generate(SudokuBoard& board, int emptyCells = 40);
};
#endif // __SUDOKOGENERATOR_H__