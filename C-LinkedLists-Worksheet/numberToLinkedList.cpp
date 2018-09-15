/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N)
{
	if (N == 0)
	{
		node *ptr = (node *)malloc(sizeof(node));
		ptr->num = N;
		ptr->next = NULL;
		return ptr;
	}

	node *ptr = NULL, *end = NULL;

	if (N < 0)
		N = N * -1;

	while (N != 0)
	{
		ptr = (node *)malloc(sizeof(node));
		ptr->num = N % 10;
		if (end == NULL)
		{
			ptr->next = NULL;
			end = ptr;
		}
		else
		{
			ptr->next = end;
			end = ptr;
		}
		N /= 10;
	}
	return ptr;
}