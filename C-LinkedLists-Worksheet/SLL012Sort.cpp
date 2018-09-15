/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head)
{

	int zeroCount = 0, oneCount = 0, twoCount = 0;
	node *temp = (*head);
	while (temp != NULL)
	{
		if (temp->data == 0)
			zeroCount++;
		else if (temp->data == 1)
			oneCount++;
		else
			twoCount++;
		temp = temp->next;
	}
	temp = (*head);
	while (temp != NULL)
	{
		if (zeroCount > 0)
		{
			temp->data = 0;
			zeroCount--;
		}
		else if (oneCount > 0)
		{
			temp->data = 1;
			oneCount--;
		}
		else
		{
			temp->data = 2;
			twoCount--;
		}
		temp = temp->next;
	}
}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head)
{
	node *temp = (*head);
	node *link = temp->next;
	node *zero = NULL;
	node *zerotemp = NULL;
	node *one = NULL;
	node *onetemp = NULL;
	node *two = NULL;
	node *twotemp = NULL;

	while (temp != NULL)
	{
		if (temp->data == 0)
		{
			if (zero == NULL)
			{
				zero = temp;
				zero->next = NULL;
				zerotemp = zero;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
			else
			{
				temp->next = NULL;
				zerotemp->next = temp;
				zerotemp = zerotemp->next;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
		}
		if (temp->data == 1)
		{
			if (one == NULL)
			{
				one = temp;
				one->next = NULL;
				onetemp = one;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
			else
			{
				temp->next = NULL;
				onetemp->next = temp;
				onetemp = onetemp->next;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
		}
		if (temp->data == 2)
		{
			if (two == NULL)
			{
				two = temp;
				two->next = NULL;
				twotemp = two;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
			else
			{
				temp->next = NULL;
				twotemp->next = temp;
				twotemp = twotemp->next;
				temp = link;
				if (link != NULL)
					link = temp->next;
				continue;
			}
		}
	}
	if (zero != NULL)
	{
		(*head) = zero;
		if (one != NULL)
		{
			zerotemp->next = one;
			if (two != NULL)
				onetemp->next = two;
		}
		else
		{
			if (two != NULL)
				zerotemp->next = two;
		}
	}
	else if (one != NULL)
	{
		(*head) = one;
		if (two != NULL)
			onetemp->next = two;
	}
	else
	{
		(*head) = two;
	}
}