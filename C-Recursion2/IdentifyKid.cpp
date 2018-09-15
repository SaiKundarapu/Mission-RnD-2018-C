/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of �ABC�)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
#include<math.h>

void Rotations(char order[3], int noOfRot)
{
	int min = noOfRot % 3;

	for (int i = 0; i < noOfRot; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			char temp = order[j];
			order[j] = order[j + 1];
			order[j + 1] = temp;
		}
	}
}

char Generation(int n, int k, int level, char order[3])
{
	int rem = 0, index = 0, temp = pow(3.0, n - level);
	index = k / temp;
	if (level < n)
	{
		if (k%temp == 0)
			index--;
		if (index > 0)
			Rotations(order, index);
		char result = Generation(n, k, level + 1, order);
		return result;
	}
	if (level == n){
		int result = index % 3;
		if (result == 0)
			return order[2];
		return order[result - 1];
	}
	else
		return '\0';
}

char identifyKid(int N, int K) {

	if (N < 1 || K < 1 || K>pow(3.0, N))
		return '\0';

	char order[3] = { 'A', 'B', 'C' };
	char result = Generation(N, K, 1, order);

	return result;
}