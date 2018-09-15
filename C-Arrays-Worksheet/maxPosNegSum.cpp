
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1)

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input, int length)
{
	int maxpos = 0, maxneg = 0, i;
	bool flagpos = false, flagneg = false, flagzero = false;

	for (i = 0; i < length; i++)
	{

		if (input[i] > 0 && maxpos == 0)
		{
			flagpos = true;
			maxpos = input[i];
		}
		else if (input[i]>0 && input[i] > maxpos)
			maxpos = input[i];

		if (input[i] < 0 && maxneg == 0)
		{
			flagneg = true;
			maxneg = input[i];
		}
		else if (input[i] < 0 && input[i] > maxneg)
			maxneg = input[i];

		if (input[i] == 0)
			flagzero = true;
	}

	if (flagzero == true)
		return maxpos + maxneg;

	if (flagpos == false || flagneg == false)
		return 0;

	return (maxpos + maxneg);
}
