game: main.o GameOfLife.o
	g++ -std=c++17 -o game main.o GameOfLife.o
main.o : main.cpp GameOfLife.h
	g++ -std=c++17 -c main.cpp
GameOfLife.o : GameOfLife.cpp GameOfLife.h
	g++ -std=c++17 -c GameOfLife.cpp
clean:
	rm game main.o GameOfLife.o
