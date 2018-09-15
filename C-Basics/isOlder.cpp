/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


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

int isOlder(char *dob1, char *dob2)
{
	int DStart = 0;
	int DEnd = 1;
	int MStart = 3;
	int MEnd = 4;
	int YStart = 6;
	int YEnd = 9;

	if (dob1[2] != '-' || dob2[2] != '-' || dob1[5] != '-' || dob2[5] != '-')
		return -1;

	int d1 = extractDate(dob1);
	int m1 = extractMonth(dob1);
	int y1 = extractYear(dob1);

	int d2 = extractDate(dob2);
	int m2 = extractMonth(dob2);
	int y2 = extractYear(dob2);

	if (m1 > 12 || m1 < 1 || m2 > 12 || m2<1)
		return -1;

	if (d1 < 1 || d2 < 1 || d1 > 31 || d2 > 31)
		return -1;

	//check for leap year of dob 1
	if (m1 == 2)
	{
		if (y1 % 4 == 0){
			if (d1 > 29)
				return -1;
		}
		else
			if (d1 > 28)
				return -1;
	}

	//check for leap year of dob 2
	if (m2 == 2)
	{
		if (y2 % 4 == 0){
			if (d2 > 29)
				return -1;
		}
		else
			if (d2 > 28)
				return -1;
	}


	int i;

	for (i = YStart; i <= YEnd; i++)
	{
		if (dob1[i] < dob2[i])
		{
			return 1;
		}
		if (dob1[i] > dob2[i])
		{
			return 2;
		}

	}
	for (i = MStart; i <= MEnd; i++)
	{
		if (dob1[i] < dob2[i])
		{
			return 1;
		}
		if (dob1[i] > dob2[i])
		{
			return 2;
		}

	}
	for (i = DStart; i <= DEnd; i++)
	{
		if (dob1[i] < dob2[i])
		{
			return 1;
		}
		if (dob1[i] > dob2[i])
		{
			return 2;
		}

	}
	return 0;

}