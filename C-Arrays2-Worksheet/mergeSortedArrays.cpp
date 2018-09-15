/*
OVERVIEW: You are given 2 bank statements that are ordered by date -
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

void getDate(char *date, int *d, int *m, int *y)
{
	sscanf_s(date, "%d-%d-%d", d, m, y);
}

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
		return NULL;

	transaction *out = (transaction*)malloc((ALen + BLen)*sizeof(transaction));

	int y1, m1, d1, y, m, d;

	int i = 0, j = 0, k = 0;
	getDate(A[i].date, &d, &m, &y);
	getDate(B[j].date, &d1, &m1, &y1);

	while (i < ALen && j < BLen)
	{

		if (y < y1)
		{
			out[k] = A[i];
			k++;
			i++;
			getDate(A[i].date, &d, &m, &y);
			continue;

		}
		else if (y == y1)
		{
			if (m < m1)
			{
				out[k] = A[i];
				k++;
				i++;
				getDate(A[i].date, &d, &m, &y);
				continue;
			}

			else if (m == m1)
			{
				if (d < d1)
				{
					out[k] = A[i];
					k++;
					i++;
					getDate(A[i].date, &d, &m, &y);
					continue;
				}
				else if (d == d1)
				{
					out[k] = A[i];
					k++;
					i++;
					out[k] = B[j];
					k++;
					j++;
					getDate(A[i].date, &d, &m, &y);
					getDate(B[j].date, &d1, &m1, &y1);
					continue;
				}
			}

		}
		out[k] = B[j];
		k++;
		j++;
		getDate(B[j].date, &d1, &m1, &y1);
	}

	while (i < ALen)
	{
		out[k] = A[i];
		k++;
		i++;
	}
	while (j < BLen)
	{
		out[k] = B[j];
		k++;
		j++;
	}

	return out;
}