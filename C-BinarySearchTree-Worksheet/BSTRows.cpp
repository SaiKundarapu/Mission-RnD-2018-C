/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int height(struct node *root)
{
	if (root == NULL)
		return 0;

	int leftHeight, rightHeight;
	leftHeight = height(root->left);
	rightHeight = height(root->right);

	if (leftHeight > rightHeight)
		return 1 + leftHeight;
	else
		return 1 + rightHeight;
}


int insert(int *arr, int level, int index, struct node *root)
{
	if (root == NULL)
		return index;
	if (level == 1)
		arr[index++] = root->data;
	else
	{
		index = insert(arr, level - 1, index, root->right);
		index = insert(arr, level - 1, index, root->left);
	}
	return index;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int h = height(root);
	int *arr = (int *)malloc(25*sizeof(int));
	int index = 0,level;
	for (level = 1; level <= h; level++)
	{
		index = insert(arr, level, index, root);
	}
	return arr;
}