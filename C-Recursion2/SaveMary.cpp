/*
Raju bhai is a new don in town. He enjoys hanging people every weekend.
This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K.
He framed certain rules to hang people.

Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
Rule 2: He always starts counting from 1st person.
Rule 3: The last person will be allowed to live for rest of his life.

Sample Case:
Given N=5, K=2
Initial state: 1,2,3,4,5
Step 1: skips 1 and hangs 2
1,3,4,5
Step 2: Now skips 3 and hangs 4
1,3,5
Step 3: Now skips 5 and hangs 1
3,5
Step 4: Now skips 3 and hangs 5
3
As 3 is only person, he lets him live.

Save our friend Mary by choosing correct position in the initial circle.
You have to return the integer x, such that if mary is positioned at x in [1..N] she
will not be killed, if no such position exists, return -1
Fill the below function with code and return the postion.
Return -1 for error cases
*/
#include<stdio.h>
#include<stdlib.h>

int killPos(int n, int k, int *killedpos, int killingpos, int skipcount)
{
	killingpos++;
	if (skipcount == k - 1)
	{
		if (killingpos >n || killedpos[killingpos] == 0)
		{
			if (killingpos  > n)
				killingpos = 1;
			while (killedpos[killingpos] == 0)
			{
				killingpos++;
				if (killingpos > n)
				{
					killingpos = 1;
					while (killedpos[killingpos] == 0)
					{
						killingpos++;
					}
				}
			}
		}
		else
		{
			if (killingpos > n)
			{
				killingpos = 1;
				while (killedpos[killingpos] == 0)
				{
					killingpos++;
				}
			}
		}
		return killingpos;
	}


	if (killingpos >n || killedpos[killingpos] == 0)
	{
		if (killingpos  > n)
			killingpos = 1;
		while (killedpos[killingpos] == 0)
		{
			killingpos++;
			if (killingpos > n)
			{
				killingpos = 1;
				while (killedpos[killingpos] == 0)
				{
					killingpos++;
				}
			}
		}
	}
	else
	{
		if (killingpos > n)
		{
			killingpos = 1;
			while (killedpos[killingpos] == 0)
			{
				killingpos++;
			}
		}
	}
	return killPos(n, k, killedpos, killingpos, skipcount + 1);

}

int maryPos(int n, int k, int killcount, int sum, int *killedpos, int killingpos)
{
	if (killcount == n - 1)
		return sum;
	killingpos = killPos(n, k, killedpos, killingpos, 0);
	sum = sum - killingpos;
	killedpos[killingpos] = 0;
	return maryPos(n, k, killcount + 1, sum, killedpos, killingpos);

}
int saveMary(int n, int k)
{
	if (n < 1 || k < 1)
		return -1;

	int sum = (n*(n + 1)) / 2;
	int *a = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 0; i <= n; i++)
	{
		a[i] = -1;
	}

	return maryPos(n, k, 0, sum, a, 0);
}