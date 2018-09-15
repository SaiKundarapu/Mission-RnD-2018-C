/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for
octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num < 0)
		return 0;

	int dec = 0, i = 0, rem;
	while (num != 0)
	{
		rem = num % 10;
		dec = dec + rem*pow(8.0, i);
		num = num / 10;
		i++;
	}

	int hex = 0;
	i = 0;

	while (dec != 0)
	{
		rem = dec % 16;
		hex = hex + rem*pow(10.0, i);
		dec /= 16;
		i++;
	}

	return hex;

}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}