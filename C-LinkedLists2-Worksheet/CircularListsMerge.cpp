/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int length(struct node *head)
{
	struct node *temp = head;
	int len = 0;
	while (temp->next != head)
	{
		len++;
		temp = temp->next;
	}
	return len + 1;
}
int merge_circularlists(struct node **head1, struct node **head2)
{
	if (*head1 == NULL && *head2 == NULL)
		return -1;

	else if (*head1 == NULL)
	{
		return length(*head2);
		*head1 = *head2;
	}
	else if (*head2 == NULL)
		return length(*head1);

	node *current1 = *head1, *current2 = *head2, *temp = NULL, *head = NULL;
	int i = 0, j = 0, len1 = length(*head1), len2 = length(*head2);

	if (current1->data < current2->data)
	{
		temp = current1;
		current1 = current1->next;
		i++;
	}
	else
	{
		temp = current2;
		current2 = current2->next;
		j++;
	}
	head = temp;

	while (i != len1 && j != len2)
	{
		if (current1->data < current2->data)
		{
			temp->next = current1;
			temp = temp->next;
			current1 = current1->next;
			i++;
		}
		else
		{
			temp->next = current2;
			temp = temp->next;
			current2 = current2->next;
			j++;
		}
	}

	if (i == len1)
	{
		while (j != len2)
		{
			temp->next = current2;
			temp = temp->next;
			current2 = current2->next;
			j++;
		}
		temp->next = head;
	}
	if (j == len2)
	{
		while (i != len1)
		{
			temp->next = current1;
			temp = temp->next;
			current1 = current1->next;
			i++;
		}
		temp->next = head;
	}
	*head1 = head;
	return (len1 + len2);

}