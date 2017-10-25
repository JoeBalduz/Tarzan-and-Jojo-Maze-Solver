# Tarzan-and-Jojo-Maze-Solver
Solves Tarzan and Jojo style mazes.

This program solves Tarzan and Jojo style mazes. Here is an image of one such maze: https://i.imgur.com/AFUlOGs.jpg.

How these mazes work: From the given picture, Tarzan starts at the very top and has to get to Jojo who is at the very bottom.
Tarzan can move 3 to 4 spaces at a time going in the direction that is specified on the block he is at. In the picture,
Tarzan can move 3 spots down to A or 4 spots down to B. If he lands on A, he can then go 3 or 4 spots to the right. If he lands
on B, he can only move up to 3 spots down since the maze stops there.

This program should be run in a Linux/UNIX terminal. A make file has been included. To run the program call the make and then
start the program by inputing ./MazeSolver. The program will then ask for an input file. Two input files have been included, input.txt
and tarzan.txt, but you can make your own as long as it follows the format of the two given input files. The program will then solve
the maze if it's possible. If it's impossible for Tarzan to get to Jojo, then a message will be displayed to the screen saying that
Jojo can't be found. Otherwise, the program will create a new file that tells you how to solve the maze. 

This program works by creating a 2D array from the specified input file. From that array, the program then creates an adjacency 
matrix. The adjacency matrix will tell whether you can travel from one vertex to another and how far that distance is. A 
depth-first search algorithm is then used on the adjacency matrix to figure out how to solve the maze.
