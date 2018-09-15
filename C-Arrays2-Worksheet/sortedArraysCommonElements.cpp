/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input:
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include <iostream>
#include <conio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int extractdate(char* str)
{
	int DStart = 0;
	int DEnd = 1;

	int n = 0, i;

	for (i = DStart; i <= DEnd; i++)
	{
		n = n * 10 + (str[i] - 48);
	}
	return n;
}

int extractmonth(char* str)
{
	int MStart = 3;
	int MEnd = 4;

	int n = 0;

	for (int i = MStart; i <= MEnd; i++)
	{
		n = n * 10 + (str[i] - 48);
	}
	return n;

}

int extractyear(char* str)
{
	int YStart = 6;
	int YEnd = 9;

	int n = 0;

	for (int i = YStart; i <= YEnd; i++)
	{
		n = n * 10 + (str[i] - 48);
	}
	return n;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;

	transaction ** out = (transaction**)malloc(ALen*sizeof(transaction));
	*out = NULL;
	int k = 0;

	for (int i = 0; i < ALen; i++)
	{
		for (int j = 0; j < BLen; j++)
		{
			if (extractdate(A[i].date) == extractdate(B[i].date))
				if (extractmonth(A[i].date) == extractmonth(B[i].date))
					if (extractyear(A[i].date) == extractyear(B[i].date))
						out[k++] = &A[i];
		}
	}
	return *out;
}