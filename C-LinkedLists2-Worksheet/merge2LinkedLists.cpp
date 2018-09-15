/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};


struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{

	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	node *head = NULL;
	node *cur = NULL;
	node *cur1 = head1, *cur2 = head2;

	if (cur1->num < cur2->num)
	{
		cur = cur1;
		cur1 = cur1->next;
	}
	else
	{
		cur = cur2;
		cur2 = cur2->next;
	}

	head = cur;


	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->num < cur2->num)
		{
			cur->next = cur1;
			cur = cur1;
			cur1 = cur1->next;
		}
		else
		{
			cur->next = cur2;
			cur = cur2;
			cur2 = cur2->next;
		}
	}

	if (cur1 == NULL)
		cur->next = cur2;
	else
		cur->next = cur1;

	return head;
}
