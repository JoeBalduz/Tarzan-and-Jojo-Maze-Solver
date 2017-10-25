#include <stack>
#include <fstream>
#include "MazeSolver.h"


//Used for testing. Prints out the array
void printArray(string **arr, int rows, int columns)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

//Used for testing. Prints out the matrix
void printMatrix(int **arr, int count)
{
	int i, j;
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count; j++)
		{
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

int main()
{
	int rows, columns;
	int startingRow, startingColumn;
	int count = 0;
	int i, j, l, m;				//Iterators
	int jojo_found = 0;
	stack<vertices> path;		//Path currently being traveled
	stack<vertices> solution;	//Solution to get to Jojo
	vertices current;			//Current location
	vertices next;				//Where to go next
	vertices print;				//Used when printing out the stack
	string fileName;
	string outputFileName;

	fstream myFile;
	ofstream fileWrite;

	cout << "Enter in the name of the file: ";
	cin >> fileName;

	myFile.open(fileName.c_str());

	if(!myFile)
	{
		cout << fileName << " does not exist.\n";
		exit(1);
	}
	
	for(i = 0; fileName[i] != '.'; i++)
		outputFileName += fileName[i];

	outputFileName += "Solved.txt";

	fileWrite.open(outputFileName.c_str());

	//Gets dimensions of graph, as well as Tarzan's starting point
	myFile >> rows >> columns >> startingRow >> startingColumn;


	//Allocates array for input
	string **input = (string **)malloc(rows * sizeof(string *));
	input = new string*[rows];
	for(l = 0; l < rows; l++)
	{
		input[l] = (string *)malloc(columns * sizeof(string));
		input[l] = new string[columns];
	}

	//Creates array of given graph
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			myFile >> input[i][j];
			
			//Finds number of vertices
			if(input[i][j] != "X")
			{
				count++;	
			}
		}
	}

	myFile.close();

	//Allocates array for adjacency matrix
	int **matrix = (int **)malloc(count * sizeof(int *));
        matrix = new int*[count];
        for(m = 0; m < count; m++)
	{
                matrix[m] = (int *)malloc(count * sizeof(int));
                matrix[m] = new int[count];
        }
	
	int k = 0;

	//Creates vertices
	vertices vertex[count];
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			if(input[i][j] != "X")
			{
				vertex[k].direction = input[i][j];
				vertex[k].visited = 0;
				vertex[k].x = i;
				vertex[k].y = j;
				vertex[k].number = k;
				
				//Checks to see if it is Tarzan's starting point
				if(i == (startingRow - 1) && j == (startingColumn - 1))
				{
					vertex[k].startingPoint = 1;
				}
				else
				{
					vertex[k].startingPoint = 0;
				}
				k++;
			}
		}
	}

	createMatrix(matrix, input, rows, columns, count, vertex);

	//Finds Tarzan's starting point and sets it to current
	for(k = 0; k < count; k++)
	{
		if(vertex[k].startingPoint == 1)
		{
			vertex[k].visited = 1;
			current = vertex[k];
			break;
		}
	}

	next = getNeighbor(matrix, current, count, vertex);

	//Distance from current to next is found
	current.distance = matrix[current.number][next.number];
	
	path.push(current);
	current = next;

	//Looks for a way to find Jojo. Performs DFS
	while(path.empty() != 1)
	{
		if(current.direction == "J")
		{
			jojo_found = 1;
			break;
		}

		next = getNeighbor(matrix, current, count, vertex);

		//When distance is -1, it means that every neighbor has been visited
		if(next.distance == -1)
		{
			current = path.top();
			path.pop();
		}
		else
		{
			current.distance = matrix[current.number][next.number];
			path.push(current);
			current = next;
		}
	}

	if(jojo_found)
	{
		//Copies the path to solution so that it may be printed out in the correct order
		while(path.empty() != 1)
		{
			solution.push(path.top());
			path.pop();		
		}
		while(solution.empty() != 1)
		{
			print = solution.top();
			solution.pop();
			fileWrite << print.direction << "-" << print.distance << " ";
		}
	}
	else
	{
		cout << "Jojo can't be found.\n";
	}

	deleteInputArray(input, rows);	

	deleteMatrixArray(matrix, count);

	return 0;
}
