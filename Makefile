CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = bin/SudokuGame.exe

# List all object files
OBJECTS = obj/main.o obj/SudokuBoard.o obj/SudokuSolver.o obj/SudokuGame.o obj/SudokuGenerator.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

obj/main.o: src/main.cpp include/SudokuGame.hpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/SudokuBoard.o: src/SudokuBoard.cpp include/SudokuBoard.hpp
	$(CXX) $(CXXFLAGS) -c src/SudokuBoard.cpp -o obj/SudokuBoard.o

obj/SudokuSolver.o: src/SudokuSolver.cpp include/SudokuSolver.hpp
	$(CXX) $(CXXFLAGS) -c src/SudokuSolver.cpp -o obj/SudokuSolver.o

obj/SudokuGame.o: src/SudokuGame.cpp include/SudokuGame.hpp
	$(CXX) $(CXXFLAGS) -c src/SudokuGame.cpp -o obj/SudokuGame.o

obj/SudokuGenerator.o: src/SudokuGenerator.cpp include/SudokuGenerator.hpp
	$(CXX) $(CXXFLAGS) -c src/SudokuGenerator.cpp -o obj/SudokuGenerator.o

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
.PHONY: all clean