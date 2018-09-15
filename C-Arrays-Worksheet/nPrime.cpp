/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>
int* nPrime(int n)
{
	if (n <= 0)
		return NULL;

	bool *prime = (bool*)malloc(n*sizeof(bool));
	int *np = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; i++)
		prime[i] = true;

	for (int p = 2; p*p <= n; p++)
	{

		if (prime[p] == true)

		{
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	int j = 0;

	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == true)
		{
			np[j] = i;
			j++;
		}
	}
	return np;
}