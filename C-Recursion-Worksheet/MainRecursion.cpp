/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/
	const int n = 5, m = 5;
	int blocks[n][m] = {
		{ 1, 2, 0, 1, 0 },
		{ 0, 3, 0, 9, 0 },
		{ 0, 4, 0, 8, 0 },
		{ 0, 1, 1, 4, 0 },
		{ 0, 0, 2, 3, 0 }, };
	const int jc_exp = 4;
	int jc = 0;
	int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 5, 6 };
	int nopath = 0;
	int *res = pillars_max_jumps(&blocks[0][0], n, m, &jc);
	for (int i = 0; i <= jc; i++)
	{
		printf("%d", res[i]);
	}
	return 0;
}