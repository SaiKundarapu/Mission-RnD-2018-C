/*
OVERVIEW:
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num < 0)
		return 0;

	int oct = 0, rem, i = 1;

	while (num != 0)
	{
		rem = num % 8;
		num = num / 8;
		oct = oct + (rem*i);
		i = i * 10;
	}
	return oct;

}

float decimalToOctalFraction(float num)
{
	int dInt, i = 1, oInt = 0, rem, temp;
	float dFra, oFra = 0.0, j = 0.1, fraoct;
	dInt = num;
	dFra = num - dInt;

	while (dInt != 0)
	{
		rem = dInt % 8;
		oInt = oInt + rem*i;
		dInt = dInt / 8;
		i = i * 10;
	}

	for (i = 1; i <= 2; i++){

		dFra = dFra * 8;
		temp = dFra;

		oFra = oFra + j*temp;
		dFra = dFra - temp;

		j = j / 10;
	}


	fraoct = oInt + oFra;
	return fraoct;

}


