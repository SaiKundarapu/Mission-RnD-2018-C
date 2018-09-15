/*
	problemCode : maxGold
	score : 20


 * Question:    Ragnar Lothbrok, a famous treasure collector went on an expedition to Paris. The Paris king offered him
 *              gold but the amount of gold offering depends on this problem.
 *				
 *              Ragnar need to start from the root of the 3-ary TREE and should reach any leaf. In this tree,
 *              each node contains either 0 or 1. Along the path travelled by Ragnar (root to leaf), forms a binary
 *              number. Ragnar will get the gold in tons of decimal value of the binary number.
 *
 *				A 3-ary tree is similar to any other tree except each node can have a maximum of 3 children.
 *
 *              Ragnar asked his intelligent friend Loki (you). How much maximum gold can they get,
 *
 * Example:                 1
 *                     /    |    \
 *                  0       1       0
 *                / | \   / | \   / | \   
 *               0  1  1 1  0  0 1  1  0
 *
 * Explanation:     In the above example, root to leaf paths are 100, 101, 101, 111, 110, 110, 101, 101, 100
 *                  Amoung them, 111 forms are highest decimal value which is 7.
 *                  So, Ragnar Lothbrok gets 7 tons of gold.
 *                  Return 7.
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int bin;
    struct node* firstnode;
    struct node* secondnode;
	struct node* thirdnode;
};



int MaxGold(struct node* root) {
	return -1;
}
