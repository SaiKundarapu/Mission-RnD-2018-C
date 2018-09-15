/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>


int findmaxjumps(int* jumpsblock, int r, int c, int i, int j, int *blocks)
{
	int max = 1;

	if (blocks[i*c + j] == 0)
	{
		return 0;
	}
	if (i >= r || j >= c || i < 0 || j < 0)
		return 0;

	if (jumpsblock[i*c + j] != -1)
		return jumpsblock[i*c + j];

	if (j + 1 <c && blocks[i*c + j + 1] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + findmaxjumps(jumpsblock, r, c, i, j + 1, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if (i + 1 <r && blocks[(i + 1)*c + j] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + findmaxjumps(jumpsblock, r, c, i + 1, j, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if ((j - 1) >= 0 && blocks[i*c + j - 1] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + findmaxjumps(jumpsblock, r, c, i, j - 1, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if ((i - 1) >= 0 && blocks[(i - 1)*c + j] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + findmaxjumps(jumpsblock, r, c, i - 1, j, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	jumpsblock[i*c + j] = max;

	return max;
}
void findpath(int* jumpsblock, int r, int c, int i, int j, int* path, int k, int *blocks)
{
	if (jumpsblock[i*c + j] == 0)
		return;

	path[k++] = blocks[i*c + j];

	if (i - 1 >= 0 && jumpsblock[(i - 1)*c + j] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[(i - 1)*c + j])
		findpath(jumpsblock, r, c, i - 1, j, path, k, blocks);

	if (j + 1 < c && jumpsblock[i*c + j + 1] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[i*c + j + 1])
		findpath(jumpsblock, r, c, i, j + 1, path, k, blocks);

	if (i + 1 < r && jumpsblock[(i + 1)*c + j] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[(i + 1)*c + j])
		findpath(jumpsblock, r, c, i + 1, j, path, k, blocks);

	if (j - 1 >= 0 && jumpsblock[i*c + j - 1] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[i*c + j - 1])
		findpath(jumpsblock, r, c, i, j - 1, path, k, blocks);

}
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count)
{
	if (blocks == NULL || n <0 || m<0)
		return NULL;
	int *jumpsblock = (int*)malloc(m*n*sizeof(int));
	for (int i = 0; i < n*m; i++)
	{
		jumpsblock[i] = -1;
	}
	int x = 0;
	int y = 0;
	int maxjumps = 0;
	int jumps = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			jumps = findmaxjumps(jumpsblock, n, m, i, j, blocks);

			if (jumps > maxjumps)
			{
				maxjumps = jumps;
				x = i;
				y = j;
			}
		}
	}

	*jumps_count = maxjumps - 1;

	if (maxjumps == 0)
		return NULL;

	int* path = (int*)malloc(sizeof(int) * (maxjumps));

	findpath(jumpsblock, n, m, x, y, path, 0, blocks);

	return path;
}