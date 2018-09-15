/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int intToStr(char* str, int num, int index)
{
	char* begin = str + index;

	if (num == 0)
	{
		str[index] = '0';
		index++;
		return index;
	}
	while (num != 0)
	{
		str[index] = '0' + num % 10;
		num /= 10;
		index++;
	}
	char* end = str + index - 1;

	while (begin < end)
	{
		int temp;
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}

	return index;
}

void number_to_str(float number, char *str, int afterdecimal)
{
	int j;
	int numPart;
	float floatPart;

	if (number < 0){

		number = number * -1;
		numPart = (int)number;
		floatPart = number - numPart;
		j = 0;
		str[j++] = '-';
	}
	else
	{
		numPart = (int)number;
		floatPart = number - numPart;
		j = 0;
	}

	j = intToStr(str, numPart, j);

	if (floatPart == 0)
	{
		str[j] = '\0';
		return;
	}

	else
	{
		str[j++] = '.';

		int decimalFloatPart;

		while (afterdecimal != 0)
		{
			floatPart *= 10;
			decimalFloatPart = (int)floatPart;
			floatPart -= decimalFloatPart;
			afterdecimal--;
			j = intToStr(str, decimalFloatPart, j);
		}

		str[j] = '\0';
	}

}