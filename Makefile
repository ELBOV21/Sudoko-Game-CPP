# Force Make to use PowerShell instead of the legacy cmd.exe
SHELL := powershell.exe

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = bin/SudokuGame.exe

# List all source files in the src folder
SOURCES = src/main.cpp src/SudokuBoard.cpp src/SudokuSolver.cpp src/SudokuGame.cpp

# Automatically map src/*.cpp to obj/*.o
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile .cpp to .o, and make them depend on your header files
obj/%.o: src/%.cpp include/SudokuBoard.hpp include/SudokuSolver.hpp include/SudokuGame.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)