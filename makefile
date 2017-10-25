make: MazeSolver.o
	g++ MazeSolver.o -o MazeSolver

MazeSolver.o: MazeSolver.cpp
	g++ -c MazeSolver.cpp

clean:
	rm *.o MazeSolver
