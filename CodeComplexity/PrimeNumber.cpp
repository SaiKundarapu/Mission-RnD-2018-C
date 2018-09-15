/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

BruteForce:
1.Loopcount= 5, Number=232910011, Time= 3.430000 seconds
2.Loopcount= 1, Number=2147483647, Time= 6.285000 seconds

SquareRoot:
1.LoopCount=10000, Number=232910011, Time= 1.297000 seconds
2.LoopCount=100, Number=2147483647, Time= 0.046000 seconds

Optimized :
1.LoopCount=1000, Number=232910011, Time= 0.062000 seconds
2.LoopCount=100, Number=2147483647, Time= 0.016000 seconds

Conclusion :
BruteForce:
TimeComplexity:O(n)
This can't be for large number.
SquareRoot:
TimeComplexity:O(sqrt(n))
This is better can be used for avg cases.
Reason to do it till just square root of number: If n = a*b and a <= b then a*a <= a*b = n.
Optimized :
TimeComplexity:O(sqrt(n)/2)
This is more efficient to use as it is till reduced only for odd numbers.
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number)
{
	int i, factor = 0;
	for (int i = 1; i < number; i++)
		if (number%i == 0)
			factor++;
	if (factor == 1)
		return 1;
	return 0;

}

/*
Is checking division till number neccesary?

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number)
{
	int i, factor = 0;
	for (i = 1; i <= sqrt((double)number); i++)
		if (number%i == 0)
			factor++;
	if (factor == 1)
		return 1;
	return 0;
}

/*
Add more optimizations you like,
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number)
{
	int i;

	if (number == 2)
		return 1;

	if (number % 2 == 0)
		return 0;

	for (i = 3; i <= sqrt((double)number); i += 2)
		if (number%i == 0)
			return 0;

	return 1;
}


