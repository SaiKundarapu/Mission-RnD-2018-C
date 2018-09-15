/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverseString(char* str, int length)
{
	int i, j;
	char temp;

	j = length - 1;
	for (i = 0; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void str_words_in_rev(char *input, int len)
{
	int i = 0, j = 0;
	reverseString(input, len);
	while (1)
	{
		if (*(input + j) == ' ' || *(input + j) == '\0')
		{
			reverseString(input + i, j - i);
			i = j + 1;
		}
		if (*(input + j) == '\0')
		{
			break;
		}
		j++;
	}
}

