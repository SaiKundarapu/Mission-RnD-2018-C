/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>

int slength(char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char *performOperation(char *str1, char *str2, char *operation)
{
	int len1, len2, len;

	len1 = slength(str1);
	len2 = slength(str2);

	if (len1 >= len2)
		len = len1;
	else
		len = len2;
	int i = len1 - 1, j = len2 - 1, k = len - 1;

	char* out = (char*)malloc((len + 1)*sizeof(char));


	if (operation[0] == 'A')
	{
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '1'&&str2[j] == '1')
				out[k] = '1';
			else
				out[k] = '0';

			k--;
			i--;
			j--;
		}
		if (j < 0)
		{
			while (i >= 0)
			{
				out[k] = '0';
				k--;
				i--;
			}
		}
		else
		{
			while (j >= 0)
			{
				out[k] = '0';
				k--;
				j--;
			}
		}
		out[len] = '\0';
	}

	if (operation[0] == 'O')
	{
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '1' || str2[j] == '1')
				out[k] = '1';
			else
				out[k] = '0';

			k--;
			i--;
			j--;
		}
		if (j < 0)
		{
			while (i >= 0)
			{
				out[k] = str1[i];
				k--;
				i--;
			}
		}
		else
		{
			while (j >= 0)
			{
				out[k] = str2[j];
				k--;
				j--;
			}
		}
		out[len] = '\0';
	}
	if (operation[0] == 'N')
	{
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '0' && str2[j] == '0')
				out[k] = '1';
			else
				out[k] = '0';

			k--;
			i--;
			j--;
		}
		if (j < 0)
		{
			while (i >= 0)
			{
				if (str1[i] == '1')
					out[k] = '0';
				else
					out[k] = '1';
				k--;
				i--;
			}
		}
		else
		{
			while (j >= 0)
			{
				if (str2[j] == '1')
					out[k] = '0';
				else
					out[k] = '1';
				k--;
				j--;
			}
		}
		out[len] = '\0';
	}
	if (operation[0] == 'X')
	{
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == str2[j])
				out[k] = '0';
			else
				out[k] = '1';

			k--;
			i--;
			j--;
		}
		if (j < 0)
		{
			while (i >= 0)
			{
				out[k] = str1[i];
				k--;
				i--;
			}
		}
		else
		{
			while (j >= 0)
			{
				out[k] = str2[j];
				k--;
				j--;
			}
		}
		out[len] = '\0';
	}
	return out;

}
