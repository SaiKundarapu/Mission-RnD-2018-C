/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_wrapper(int* spiral,int** board, int rstart, int rend, int cstart, int cend, int index)
{

	for (int i = cstart; i <= cend; i++)
		spiral[index++] = board[rstart][i];
	for (int i = rstart + 1; i <= rend; i++)
		spiral[index++] = board[i][cend];

	if (rstart + 1 <= rend)
	{
		for (int i = cend - 1; i >= cstart; i--)
			spiral[index++] = board[rend][i];
	}
	if (cstart + 1 <= cend)
	{
		for (int i = rend - 1; i > rstart; i--)
			spiral[index++] = board[i][cstart];
	}

	if (rstart + 2 <= rend && cstart + 2 <= cend)
		spiral_wrapper(spiral,board, rstart + 1, rend - 1, cstart + 1, cend - 1, index);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *output_array = (int *)malloc(sizeof(int)*(rows*columns));

	spiral_wrapper(output_array,input_array , 0, rows - 1, 0, columns - 1, 0);
	return output_array;
}