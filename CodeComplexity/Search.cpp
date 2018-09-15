/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input :
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:
For 10000 times,ArraySize=1000 Took 0.108000 seconds in bruteForce(worst case)
For 10000 times,ArraySize=1000 Took 0.017000 seconds in bruteForce(avg case)
For 1000000 times,ArraySize=1000  Took 0.029000 seconds in bruteForce(Best case)


Binary Search :
For 10000 times,ArraySize=1000 Took 0.003000 seconds in opt way(worst case)
For 10000 times,ArraySize=1000 Took 0.001000 seconds in opt way(avg case)
For 1000000 times,ArraySize=1000  Took 0.033000 seconds in opt way(Best case)
Conclusion :
1.Input data needs to be sorted in Binary Search and not in Linear Search
2.Linear search does the sequential access whereas Binary search access data randomly.
3.Time complexity of linear search- O(n) , Binary search- O(log n).
4.Linear search performs equality comparisons
5.Binary search performs ordering comparisons
*/

int linearSearch(int *arr, int len, int key)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (key == arr[i])
			break;
	}
	if (i < len)
	{
		return i;
	}

	return -1;
}



int binarySearch(int *arr, int len, int key)
{
	//Use this function as wrapper function,if you are implementing bs recursively.

	int low = 0, high = len - 1;

	while (high >= low)
	{
		int mid = (low + high) / 2;
		if (key < arr[mid])
			high = mid - 1;
		else if (key > arr[mid])
			low = mid + 1;
		else
		{
			return mid;
		}
	}

	return -1;
}