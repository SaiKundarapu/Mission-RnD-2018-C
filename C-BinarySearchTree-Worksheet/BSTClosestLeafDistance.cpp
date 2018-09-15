/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

struct node *parent_of(struct node *root, int data){

	if (root == NULL)
		return NULL;

	if (root->left != NULL){
		if (root->left->data == data)
			return root;
	}

	if (root->right != NULL){
		if (root->right->data == data)
			return root;
	}

	struct node *l = NULL;
	struct node *r = NULL;
	
	if (root->left != NULL)
		l = parent_of(root->left, data);
	
	if (root->right != NULL)
		r = parent_of(root->right, data);

	if (l == NULL && r == NULL)
		return NULL;

	if (l != NULL)
		return l;
	if (r != NULL)
		return r;
}

int minimum(int n1, int n2){

	if (n1 != -1 && n2 != -1)
	{
		if (n1 > n2)
			return n2;
		else
			return n1;
	}
	if (n1 == -1)
		return n2;
	
	if (n2 == -1)
		return n1;
	

}
int distance(struct node *root){

	if (root == NULL)
		return -1;
	if (root->left == NULL && root->right == NULL)
		return 0;

	int left = distance(root->left);
	int right = distance(root->right);

	int min = minimum(left, right);

	return min+1;
}
int closest_distance(struct node *root, struct node *temp){

	int dist = distance(temp);

	if (dist == 0 || dist == 1)
		return dist;
	int p,min;
	struct node *parent = parent_of(root, temp->data);

	if (parent != NULL){

		p = closest_distance(root, parent);
		min = minimum(p, dist);

		if (p == min)
			return p+1;
	}
	return dist;
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
  
	if (root == NULL || temp == NULL)
		return -1;

	return closest_distance(root, temp);
}