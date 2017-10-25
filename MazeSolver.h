#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct vertices
{
	string direction;
	int distance;
	int visited;	
	int x;	//x coordinate
	int y;	//y coordinate
	int startingPoint;	//If 1, Tarzan starts there	
	int number;	//Tells which number vertex it is
};

//Creates the adjacency matrix
void createMatrix(int **matrix, string **input, int rows, int columns, int count, vertices vertex[])
{
	int i, j, k, l;

	//Initializes matrix to 0
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count; j++)
		{
			matrix[i][j] = 0;
		}
	}
	//Creates the adjacency matrix with the appropriate weights	
	for(k = 0; k < count; k++)
	{
		if(vertex[k].direction == "S")
		{
			//Checks to see if there is a valid spot
			if((vertex[k].x + 3) < rows && input[vertex[k].x + 1][vertex[k].y] != "X" &&
			input[vertex[k].x + 2][vertex[k].y] != "X" && input[vertex[k].x + 3][vertex[k].y] != "X")
			{
			
				for(l = 0; l < count; l++)
				{
					if((vertex[k].x + 3) == vertex[l].x && vertex[k].y == vertex[l].y)
					{
						
						matrix[k][l] = 3;	//Distance of 3 away
						break;
					}
				}
				if((vertex[k].x + 4) < rows && input[vertex[k].x + 4][vertex[k].y] != "X")
				{
					for(l = 0; l < count; l++)
					{
						if((vertex[k].x + 4) == vertex[l].x && vertex[k].y == vertex[l].y)
						{
							matrix[k][l] = 4;	//Distance of 4 away
							break;
						}
					}
				}
			}
		}
                else if(vertex[k].direction == "N")
                {
						//Checks to see if there is a valid spot
                        if((vertex[k].x - 3) > -1 && input[vertex[k].x - 1][vertex[k].y] != "X" &&
                        input[vertex[k].x - 2][vertex[k].y] != "X" && input[vertex[k].x - 3][vertex[k].y] != "X")
                        {

                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].x - 3) == vertex[l].x && vertex[k].y == vertex[l].y)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].x - 4) > -1 && input[vertex[k].x - 4][vertex[k].y] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].x - 4) == vertex[l].x && vertex[k].y == vertex[l].y)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
                else if(vertex[k].direction == "E")
                {
						//Checks to see if there is a valid spot
                        if((vertex[k].y + 3) < columns && input[vertex[k].x][vertex[k].y + 1] != "X" &&
                        input[vertex[k].x][vertex[k].y + 2] != "X" && input[vertex[k].x][vertex[k].y + 3] != "X")
                        {

                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].y + 3) == vertex[l].y && vertex[k].x == vertex[l].x)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].y + 4) < columns && input[vertex[k].x][vertex[k].y + 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].y + 4) == vertex[l].y && vertex[k].x == vertex[l].x)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
		else if(vertex[k].direction == "W")
                {
						//Checks to see if there is a valid spot
                        if((vertex[k].y - 3) > -1 && input[vertex[k].x][vertex[k].y - 1] != "X" &&
                        input[vertex[k].x][vertex[k].y - 2] != "X" && input[vertex[k].x][vertex[k].y - 3] != "X")
                        {

                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].y - 3) == vertex[l].y && vertex[k].x == vertex[l].x)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].y - 4) > -1 && input[vertex[k].x][vertex[k].y - 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].y - 4) == vertex[l].y && vertex[k].x == vertex[l].x)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
		 else if(vertex[k].direction == "SE")
                {
						//Checks to see if there is a valid spot
                        if((vertex[k].x + 3) < rows && (vertex[k].y + 3) < columns && input[vertex[k].x + 1][vertex[k].y + 1] != "X" &&
                        input[vertex[k].x + 2][vertex[k].y + 2] != "X" && input[vertex[k].x + 3][vertex[k].y + 3] != "X")
                        {
                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].x + 3) == vertex[l].x && (vertex[k].y + 3) == vertex[l].y)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].x + 4) < rows && (vertex[k].y + 4) < columns &&  input[vertex[k].x + 4][vertex[k].y + 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].x + 4) == vertex[l].x && (vertex[k].y + 4) == vertex[l].y)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
		 else if(vertex[k].direction == "NW")
                {
						//Checks to see if there is a valid spot
                        if((vertex[k].x - 3) > -1 && (vertex[k].y - 3) > -1 && input[vertex[k].x - 1][vertex[k].y - 1] != "X" &&
                        input[vertex[k].x - 2][vertex[k].y - 2] != "X" && input[vertex[k].x - 3][vertex[k].y - 3] != "X")
                        {
                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].x - 3) == vertex[l].x && (vertex[k].y - 3) == vertex[l].y)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].x - 4) > -1 && (vertex[k].y - 4) > -1 &&  input[vertex[k].x - 4][vertex[k].y - 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].x - 4) == vertex[l].x && (vertex[k].y - 4) == vertex[l].y)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
		 else if(vertex[k].direction == "NE")
                {
					//Checks to see if there is a valid spot
                        if((vertex[k].x - 3) > -1 && (vertex[k].y + 3) < columns && input[vertex[k].x - 1][vertex[k].y + 1] != "X" &&
                        input[vertex[k].x - 2][vertex[k].y + 2] != "X" && input[vertex[k].x - 3][vertex[k].y + 3] != "X")
                        {
                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].x - 3) == vertex[l].x && (vertex[k].y + 3) == vertex[l].y)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].x - 4) > -1 && (vertex[k].y + 4) < columns &&  input[vertex[k].x - 4][vertex[k].y + 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].x - 4) == vertex[l].x && (vertex[k].y + 4) == vertex[l].y)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }
		 else if(vertex[k].direction == "SW")
                {
					//Checks to see if there is a valid spot
                        if((vertex[k].x + 3) < rows && (vertex[k].y - 3) > -1 && input[vertex[k].x + 1][vertex[k].y - 1] != "X" &&
                        input[vertex[k].x + 2][vertex[k].y - 2] != "X" && input[vertex[k].x + 3][vertex[k].y - 3] != "X")
                        {
                                for(l = 0; l < count; l++)
                                {
                                        if((vertex[k].x + 3) == vertex[l].x && (vertex[k].y - 3) == vertex[l].y)
                                        {

                                                matrix[k][l] = 3;	//Distance of 3 away
                                                break;
                                        }
                                }
                                if((vertex[k].x + 4) < rows && (vertex[k].y - 4) > -1 &&  input[vertex[k].x + 4][vertex[k].y - 4] != "X")
                                {
                                        for(l = 0; l < count; l++)
                                        {
                                                if((vertex[k].x + 4) == vertex[l].x && (vertex[k].y - 4) == vertex[l].y)
                                                {
                                                        matrix[k][l] = 4;	//Distance of 4 away
                                                        break;
                                                }
                                        }
                                }
                        }
                }

	}	
}

//Finds the neighbor of a given vertex
vertices getNeighbor(int **matrix, vertices current, int count, vertices vertex[])
{
	int i;
	vertices next;
	
	//Looks for neighbors of the given vertex
	for(i = 0; i < count; i++)
	{
		if(matrix[current.number][i] > 0 && vertex[i].visited == 0)
		{
			vertex[i].visited = 1;	
			next = vertex[i];
			next.distance = matrix[current.number][i];

			return next;	
		}
	}
	
	//If there is no neighbor, the distance to next is set to -1
	next.distance = -1;

	return next;
}

//Frees up memory
void deleteInputArray(string **arr, int rows)
{
	int i;
	for(i = 0; i < rows; i++)
	{
		delete [] arr[i];
	}
}

//Frees up memory
void deleteMatrixArray(int **arr, int count)
{
	for(int i = 0; i < count; i++)
	{
		delete [] arr[i];
	}
}
