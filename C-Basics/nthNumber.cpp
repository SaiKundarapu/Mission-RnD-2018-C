/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci()
nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	int a = 0, b = 1, c;
	int count = 2;

	if (n < 1)
		return -1;
	else if (n == 1)
		return a;
	else if (n == 2)
		return b;

	else
	{
		while (count != n)
		{
			c = b;
			b = a + b;
			a = c;
			count++;
		}
		return b;
	}
}

int nthPrime(int num)
{

	if (num < 1)
		return -1;

	int fact, count = 0, i, j = 1;

	while (count != num)
	{
		j++;
		fact = 0;

		for (i = 1; i < j; i++)
		{
			if (j%i == 0)
				fact++;
		}

		if (fact == 1)
			count++;
	}
	return j;
}