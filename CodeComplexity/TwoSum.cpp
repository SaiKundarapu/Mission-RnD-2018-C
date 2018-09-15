/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

For an array of size: 1000

Way 1 :
For 10 times, Took 0.015000 seconds
For 100 times, Took 0.148000 seconds
For 1000 times, Took 1.238000 seconds
For 10000 times, Took 12.203000 seconds
For 100000 times, Took 127.190000 seconds

Way 2 :
For 10 times, Took 0.016000 seconds
For 100 times, Took 0.009000 seconds
For 1000 times, Took 0.093000 seconds
For 10000 times, Took 0.984000 seconds
For 100000 times, Took 10.626000 seconds
For 1000000 times, Took 99.797000 seconds


Way 3:
For 10 times, Took 0.000000 seconds in 3
For 100 times, Took 0.000000 seconds in 3
For 1000 times, Took 0.000000 seconds in 3
For 10000 times, Took 0.047000 seconds in 3
For 100000 times, Took 0.437000 seconds in 3
For 1000000 times, Took 4.375000 seconds in 3

Conclusion :
way 1:	TimeComplexity:O(n*n)
This too worst,so can't be accepted.

way 2:	TimeComplexity:O(nlogn)
This can't be accepted for larger arrays.

way 3:	TimeComplexity:O(n)
This is a preproccessing method which can acceptable for larger inputs.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ?
Answer:O(n*n)
*/
int* sumoftwoBF(int *nums, int target, int len)
{
	if (nums == NULL || len <= 0)
		return NULL;

	int* n = (int *)malloc(2 * sizeof(int));

	for (int i = 0; i<len; i++)
	{
		for (int j = i + 1; j<len; j++)
		{
			if (target == (nums[i] + nums[j]))
			{
				if (nums[j]>nums[i])
				{
					n[0] = nums[i];
					n[1] = nums[j];
				}
				else
				{
					n[0] = nums[j];
					n[1] = nums[i];
				}
				return n;
			}
		}
	}
	return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add
so that total sum will become less.

What is the complexity of this method ?
Answer:O(nlogn)
*/


void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void partition(int a[], int low, int high, int &i, int &j)
{
	if (high - low <= 1)
	{
		if (a[high] < a[low])
			Swap(&a[high], &a[low]);
		i = low;
		j = high;
		return;
	}

	int mid = low;
	int pivot = a[high];
	while (mid <= high)
	{
		if (a[mid]<pivot)
			Swap(&a[low++], &a[mid++]);
		else if (a[mid] == pivot)
			mid++;
		else if (a[mid]>pivot)
			Swap(&a[mid], &a[high--]);
	}

	i = low - 1;
	j = mid;
}

// 3-way partition based quick sort
void quicksort(int a[], int low, int high)
{
	if (low >= high)
		return;

	int i, j;

	partition(a, low, high, i, j);
	quicksort(a, low, i);
	quicksort(a, j, high);
}


int* sumoftwoSortAndSearch(int *nums, int target, int len)
{
	if (nums == NULL || len <= 0)
		return NULL;

	quicksort(nums, 0, len - 1);

	int i = 0, j = len - 1;
	int* n = (int *)malloc(2 * sizeof(int));

	while (nums[i] + nums[j] != target)
	{
		if (nums[i] + nums[j] > target)
		{
			j--;
		}
		else if (nums[i] + nums[j] < target)
		{
			i++;
		}
		else
		{
			break;
		}
	}

	if (i > j)
		return NULL;

	n[0] = nums[i];
	n[1] = nums[j];
	return n;
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/

int* sumoftwoExtraArray(int *nums, int target, int len) {

	int map[100] = { 0 };
	int* n = (int*)malloc(sizeof(int) * 2);
	int diff;
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		j = nums[i];

		if (map[j] != 0)
			continue;
		else
		{
			map[j] = j;
			diff = target - j;
			if (map[diff] != 0 && diff > 0)
			{
				if (j < diff)
				{
					n[0] = map[j];
					n[1] = map[diff];
					return n;
				}
				else
				{
					n[0] = map[diff];
					n[1] = map[j];
					return n;
				}
			}
		}
	}
	return NULL;
}