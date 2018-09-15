/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#define SIZE 31

int strlen(char* str)
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

int stringTokenizer(char* str, char tokens[][25], char k)
{
	int j = 0;
	int count = 0;
	int len = strlen(str);
	bool flag = 0;

	for (int i = 0; i <= len; i++)
	{
		if (str[i] != k && str[i] != '\0' && str[i] != '\n')
		{
			tokens[count][j] = str[i];
			j++;
			flag = true;
			continue;
		}
		if (flag)
		{
			tokens[count][j] = '\0';
			count++;
			j = 0;
			flag = false;
		}
	}
	return count;
}

bool subString(char* str, char* subStr)
{
	bool flag = false;
	int len1 = strlen(str);
	int len2 = strlen(subStr);

	for (int i = 0; i<len1 - len2; i++)
	{
		int j = 0;
		while (j<len2 && str[i + j] == subStr[j])
		{
			j++;
		}
		if (j == len2)
			return true;
	}
	return false;
}

char* strcpy(char *str1)
{
	int len = strlen(str1);
	char* str2 = (char*)malloc(sizeof(char)*strlen(str1));

	int i;
	for (i = 0; i < len; i++)
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';

	return str2;
}

char** commonWords(char *str1, char *str2) {

	if (str1 == NULL || str2 == NULL)
		return NULL;

	char tokens[SIZE][25];
	char delimiter = ' ';
	int n = stringTokenizer(str2, tokens, delimiter);

	char** com = (char**)malloc(sizeof(char*)*n);

	int i, j;
	for (i = 0, j = 0; i < n; i++)
	{
		if (subString(str1, tokens[i])){
			com[j] = strcpy(tokens[i]);
			j++;
		}
	}
	if (j == 0)
		return NULL;
	return com;
}