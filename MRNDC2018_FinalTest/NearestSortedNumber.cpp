/*
	problemCode : NearestSortedNumber
	score : 15

	A Sorted Number is a number in which all its digits are in non-decending order.
	for example "129" , "222", "345", "999" are all Sorted Numbers.
	Where as the numbers "110" , "1000", "143" are not Sorted Numbers.

	You are given an integer N in the form of a string.
	
	Your task is to find the the last Sorted Number in the range [1,N]

	Sorted Numbers = [1,2,3,4,5,6,7,8,9,  11,12,13,...19,  22,23,24,.... INF]

	Sample Cases : 
	N = 10, result = 9
	N = 12, result = 12
	N = 19, result = 19
	N = 21, result = 19

	Note : 
	1) if there is no answer or the input is invalid , return NULL
	2) Input consists of no leading zeros, and output should not consist of leading zeros
	returning "0002" instead of "2" is considered as a wrong answer.

	Constraints : 
	1 <= len <= 100000 (i.e 100000 digits not integer 100000)
*/


#include<stdio.h>
#include<malloc.h>

char * NearestSortedNumber(char *N, int len)
{
	/*if (N == NULL)
		return NULL;
	char *out = (char*)malloc(sizeof(char)*len);
	char temp, n;
	int i, j, zero = 0;

	for (i = 0, j = 0; i < len; i++)
	{
		if (N[i]<'0' || N[i]>'9')
			return NULL;
		if (j == 0)
		{
			out[j] = N[i];
			j++;
		}
		else
		{
			if (N[i] = '0')
			{
				zero++;
				out[j] = '0';
				j++;
				break;
			}

			n = N[i];
			for (int k = 0; k < j; k++)
			{
				if (out[k] == '0')
				{
					break;
				}
				if (out[k]>n)
				{
					temp = out[k];
					out[k] = n;
					n = temp;
				}
			}
			out[j] = N[i];
			j++;
		}
	}

	int a = 0;

	for (i = 0; i < len; i++)
	{
		if (out[i] > N[i])
		{
			a = 1;
			break;
		}
		else if (out[i] < N[i])
		{
			a = -1;
			break;
		}

	}

	for (i = 0, j = len - 1; i < zero; i++)
	{
		out[j] = '9';
		j--;
	}

	if (a = 1)
	{ }
	*/
	return NULL;
}

