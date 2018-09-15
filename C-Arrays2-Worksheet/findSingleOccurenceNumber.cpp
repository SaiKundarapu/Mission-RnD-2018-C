/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *A, int len)
{
	if (A == NULL || len < 0)
		return -1;

	int x, sum, intLen = 32, result = 0;

	for (int i = 0; i<intLen; i++)
	{
		sum = 0;
		x = (1 << i);
		for (int j = 0; j < len; j++)
		{
			if (A[j] & x)
				sum++;
		}
		if (sum % 3)
			result |= x;
	}
	return result;
}

/*

void quicksort(int x[], int first, int last){
int pivot, j, temp, i;

if (first<last){
pivot = first;
i = first;
j = last;

while (i<j){
while (x[i] <= x[pivot] && i<last)
i++;
while (x[j]>x[pivot])
j--;
if (i<j){
temp = x[i];
x[i] = x[j];
x[j] = temp;
}
}

temp = x[pivot];
x[pivot] = x[j];
x[j] = temp;
quicksort(x, first, j - 1);
quicksort(x, j + 1, last);

}
}

int findSingleOccurenceNumber(int *A, int len) {
int i;
if (A == NULL)
return -1;
quicksort(A, 0, len - 1);
for (i = 0; i < len; i = i + 3)
{
if (!(A[i] == A[i + 1] && A[i + 1] == A[i + 2]))
{
return A[i];
}
}

}*/