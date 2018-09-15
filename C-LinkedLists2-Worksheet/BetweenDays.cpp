/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct node{
	int data;
	struct node *next;
};
int isLeapYear(int year)
{
	int val = 0;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				val = 1;
		}
		else
		{
			val = 1;
		}
	}
	return val;
}

int between_days(struct node *date1head, struct node *date2head)
{
	if (date1head == NULL || date2head == NULL)
		return -1;
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0;
	int days = 0;
	int temp;
	for (int i = 1; i <= 8; i++)
	{
		if (i < 3)
		{
			d1 = d1 * 10 + date1head->data;
			d2 = d2 * 10 + date2head->data;
		}
		else if (i >= 3 && i < 5)
		{
			m1 = m1 * 10 + date1head->data;
			m2 = m2 * 10 + date2head->data;
		}
		else
		{
			y1 = y1 * 10 + date1head->data;
			y2 = y2 * 10 + date2head->data;

		}
		date1head = date1head->next;
		date2head = date2head->next;
	}

	if (y1 > y2 || (y1 == y2&&m1 > m2) || (y1 == y2&&m1 == m2 &&d1>d2))	//SWAPING THE DATES IF DATE1 IS GREATER THAN DATE2
	{
		temp = d1;
		d1 = d2;
		d2 = temp;
		temp = m1;
		m1 = m2;
		m2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;

	}

	if (y1 == y2&&m1 == m2 && (d1 == d2 || d2 - d1 == 1))	// Consecutive Days and Same Days  returns 0
		return 0;

	if (y1 == y2&&m1 == m2)//if both dates years and months are same than just count days b/w them
	{
		days = days + (d2 - d1 - 1);
	}
	else if (y1 == y2)//if both dates only years are same 
	{
		//counting the date1's days remaining in the present month and increment the month
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
		{
			days = days + (31 - d1);

		}
		else if (m1 == 2)
		{
			if (isLeapYear(y1) == 1)
				days = days + (29 - d1);
			else
				days = days + (28 - d1);
		}
		else
		{
			days = days + (30 - d1);
		}
		m1++;

		//counting the days b/w the months of the two dates
		for (m1; m1 < m2; m1++)
		{
			if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
				days = days + 31;
			else if (m1 == 2)
			{
				if (isLeapYear(y1) == 1)
					days = days + 29;
				else
					days = days + 28;
			}
			else
			{
				days = days + 30;
			}
		}
		//counting completed days of the date2's present month
		days = days + (d2 - 1);

	}

	else
	{
		//counting the date1's days remaining in the present month and increment the month
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
		{
			days = days + (31 - d1);

		}
		else if (m1 == 2)
		{
			if (isLeapYear(y1) == 1)
				days = days + (29 - d1);
			else
				days = days + (28 - d1);
		}
		else
		{
			days = days + (30 - d1);
		}
		//increment of month
		if (m1 != 12)
			m1++;
		else
		{
			m1 = 1;
			y1++;
		}

		//counting completed days of the date2's present month and decrement the month
		days = days + (d2 - 1);
		//decrement of month
		if (m2 == 1)
		{
			m2 = 12;
			y2--;
		}
		else
			m2--;
		//after increment and decrement check whether years of both dates are same or not
		if (y1 < y2)
		{
			//counting the date1's  remaining months in the present year and increment the year
			for (m1; m1 <= 12; m1++)
			{
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
					days = days + 31;
				else if (m1 == 2)
				{
					if (isLeapYear(y1) == 1)
						days = days + 29;
					else
						days = days + 28;
				}
				else
				{
					days = days + 30;
				}
			}
			y1++;
			//counting the date2's  completed months in the present year and decrement the year
			for (m2; m2 >= 1; m2--)
			{
				if (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12)
					days = days + 31;
				else if (m2 == 2)
				{
					if (isLeapYear(y2) == 1)
						days = days + 29;
					else
						days = days + 28;
				}
				else
				{
					days = days + 30;
				}
			}
			y2--;
			//counting the remaining years
			for (y1; y1 <= y2; y1++)
			{
				if (isLeapYear(y1) == 1)
					days = days + 366;
				else
					days = days + 365;
			}
		}
		else if (y1 == y2)
		{
			//counting the remaining months
			for (m1; m1 <= m2; m1++)
			{
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
					days = days + 31;
				else if (m1 == 2)
				{
					if (isLeapYear(y1) == 1)
						days = days + 29;
					else
						days = days + 28;
				}
				else
				{
					days = days + 30;
				}
			}
		}
	}

	return days;
}