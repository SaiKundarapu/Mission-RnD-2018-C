/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int extractDate(char* str)
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

int extractMonth(char* str)
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

int extractYear(char* str)
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int out = 0;
	int y1, m1;

	int d = extractDate(date);
	int m = extractMonth(date);
	int y = extractYear(date);

	for (int i = 0; i < len; i++)
	{
		y1 = extractYear(Arr[i].date);
		if (y < y1)
			out++;
		else if (y == y1)
		{
			m1 = extractMonth(Arr[i].date);
			if (m < m1)
				out++;
			else if (m == m1)
			{
				if (d < extractDate(Arr[i].date))
					out++;
			}
		}
	}
	return out;
}