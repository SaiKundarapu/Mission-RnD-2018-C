/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};

void reversenumber(charNode * head, int *num)
{
	int sum = 0;
	sum = sum * 10 + ((head->letter) - 48);
	if (head->next != NULL)
		reversenumber(head->next, num);
	(*num) = (*num) * 10 + sum;

}
int isDivisibleSLL(struct charNode * head, int key)
{
	int sign = 1, count = 0;
	int num = 0;
	if (head == NULL || key <= 0)
		return -1;
	charNode * temp = head;
	while (temp != NULL)
	{
		count++;
		if (count == 1 && (temp->letter == '-' || temp->letter == '+'))
		{
			if (temp->letter == '-')
				sign = -1;
		}
		else if (temp->letter >= '0'&& temp->letter <= '9')
		{
			num = num * 10 + ((temp->letter) - 48);
		}
		else
		{
			return -1;
		}
		temp = temp->next;
		if (count > 10)
		{
			return -1;
		}
	}

	temp = head;
	int revnum = 0;
	reversenumber(temp->next, &revnum);

	if (head->letter >= '0'&& head->letter <= '9')
		revnum = revnum * 10 + ((head->letter) - 48);

	num *= sign;
	revnum *= sign;

	if ((num + revnum) % key == 0)
		return 1;
	else
		return 0;
}

