/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	if (K <= 1)
	{
		head = NULL;
		return head;
	}
	int count = 0;
	node *temp = NULL;
	node *cur = head;
	node *prev = head;
	while (cur != NULL)
	{
		count++;
		if (count % K == 0)
		{
			prev->next = cur->next;
			temp = cur;
			cur = cur->next;
			free(temp);
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
	return head;
}