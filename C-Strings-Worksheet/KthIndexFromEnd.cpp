/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>

int strLen(char* str)
{
	if (str == NULL)
		return -1;

	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

char KthIndexFromEnd(char *str, int K) {

	int len = strLen(str);

	if (len == 0 || str == NULL || K < 0 || K > len - 1)
		return '\0';

	char* c = (str + len - 1);

	for (int i = 0; i < K; i++)
	{
		c--;
	}
	return *c;
}