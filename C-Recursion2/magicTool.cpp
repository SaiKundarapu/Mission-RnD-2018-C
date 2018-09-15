/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
#include <stdio.h>

struct Point 
{
	int x;
	int y;
};


struct result 
{
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pix, int rows, int columns, struct Point piv, result* res, struct Point cur, int prev) 
{
	
	if (prev != 3 && (cur.x + 1) <= rows && pix[(cur.x+1)*(columns + 1) + cur.y] == pix[piv.x*(columns+1)+piv.y])
	{
		res->selected[res->size] = { cur.x + 1, cur.y };
		res->visited[(cur.x + 1)*(columns + 1) + cur.y] = true;
		res->size = res->size + 1;
		cur = { cur.x + 1, cur.y };
		select(pix, rows, columns, piv, res,cur, 1);
		cur = { cur.x-1, cur.y };

	}
	if (prev != 4 && (cur.y + 1) <= columns&&pix[(cur.x )*(columns + 1) + cur.y+1] == pix[piv.x*(columns+1)+piv.y])
	{
		res->selected[res->size] = { cur.x, cur.y+1};
		res->visited[cur.x, cur.y + 1] = true;
		res->size = res->size + 1;
		cur = { cur.x , cur.y+1 };
		select(pix, rows, columns, piv, res, cur, 2);
		cur = { cur.x, cur.y - 1 };
	}
	if (prev != 1 && (cur.x - 1) >= 0 && pix[(cur.x - 1)*(columns + 1) + cur.y] == pix[piv.x*(columns + 1) + piv.y])
	{
		res->selected[res->size] = { cur.x - 1, cur.y };
		res->visited[(cur.x - 1)*(columns + 1) + cur.y] = true;
		res->size = res->size + 1;
		cur = { cur.x - 1, cur.y };
		select(pix, rows, columns, piv, res, cur, 3);
		cur = { cur.x+1, cur.y  };
	}
	if (prev != 2 && (cur.y - 1) >= 0 && pix[(cur.x)*(columns + 1) + cur.y - 1] == pix[piv.x*(columns + 1) + piv.y])
	{
		res->selected[res->size] = { cur.x, cur.y-1 };
		res->visited[(cur.x)*(columns + 1) + cur.y - 1] = true;
		res->size = res->size + 1;
		cur = { cur.x , cur.y-1 };
		select(pix, rows, columns, piv, res, cur, 4);
		cur = { cur.x, cur.y + 1 };
	}
	
}
struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) 
{
	result res;
	Point cur;
	cur = pivot;
	if (pixels == NULL||pivot.x<0||pivot.y<0||pivot.x>m||pivot.y>n)
	{
		res.size = 0;
		res.selected = {};
		res.visited = {};
		return res;
	}
	res.selected = (Point*)malloc(sizeof(Point)*(m*n));
	res.visited =(bool*) malloc(sizeof(bool)*(m + 1));
	for (int i = 0; i <= m; i++)
	{
		res.visited[m] = malloc(sizeof(bool)*(n + 1));
	}
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			res.visited[i*(n+1)+j] = false;
		}
	}
	res.visited[cur.x*(n+1)+cur.y] = true;
	res.selected[0] = { pivot.x, pivot.y };
	res.size = 1;
	select(pixels, m, n, pivot, &res, cur,0);
	return res;
}