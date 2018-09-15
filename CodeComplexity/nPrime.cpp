
/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}


Observations: (Write down what you observed here):

Way 1:
For loop count= 1k numbervalue=1000 time taken=0.152000
For loop count=10k numbervalue=1000 time taken= 0.600000
For loop count=100k numbervalue=1000 time taken=16.335000
For loop count=1k numbervalue=100 time taken= 0.015000
For loop count=10k numbervalue=100 time taken= 0.047000
For loop count=100k numbervalue=100 time taken= 0.402000

Way 2 :
For loop count= 1k numbervalue=1000 time taken= 0.066000
For loop count=10k numbervalue=1000 time taken= 0.585000
For loop count=100k numbervalue=1000 time taken= 5.906000
For loop count=1k numbervalue=100 time taken= 0.015000
For loop count=10k numbervalue=100 time taken= 0.032000
For loop count=100k numbervalue=100 time taken= 0.187000


Way 3:
For loop count= 1k numbervalue=1000 time taken= 0.034000
For loop count=10k numbervalue=1000 time taken= 0.376000
For loop count=100k numbervalue=1000 time taken= 3.916000
For loop count=1k numbervalue=100 time taken= 0.003000
For loop count=10k numbervalue=100 time taken= 0.024000
For loop count=100k numbervalue=100 time taken=0.168000


*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int isPrime(int number)
{
	int i, factor = 0;
	for (int i = 1; i < number; i++)
		if (number%i == 0)
			factor++;
	if (factor == 1)
		return 1;
	return 0;

}
int* nPrimeBruteForce(int N)
{
	int *np = (int*)malloc(N*sizeof(int)), j = 0;

	for (int i = 1; i <= N; i++)
	{
		if (isPrime(i))
		{
			np[j++] = i;
		}
	}
	return np;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	if (N <= 1)
	{
		return NULL;
	}

	int* np = (int*)malloc(sizeof(int) * N);

	int j = 0;
	np[j++] = 2;

	for (int k = 3; k <= N; k += 2)
	{
		int factors = 0;
		int i = 1;
		while (i <= k)
		{
			if (k%i == 0){
				factors++;
			}
			i++;

		}
		if (factors == 2)
		{
			np[j] = k;
			j++;
		}
	}
	return np;
	free(np);
}

/*
Do all optimizations you can think of.

Hint :
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	int np[1000 + 1] = { 0 };

	for (int i = 2; i*i <= N; i++)
	{
		if (np[i] == 0)
		{
			for (int j = i * 2; j <= N; j = j + i)
				np[j] = 1;
		}
	}

	int* a = (int*)malloc(sizeof(int)*N);

	for (int i = 2, j = 0; i <= N; i++)
	{
		if (np[i] == 0){
			a[j] = i;
			j++;
		}

	}
	return a;
}