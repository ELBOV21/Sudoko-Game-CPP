cmake_minimum_required(VERSION 3.10)
project(SudokuGame CXX)

# Require C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the executable from the source files
add_executable(SudokuGame 
    main.cpp 
    SudokuBoard.cpp 
    SudokuSolver.cpp 
    SudokuGame.cpp
)