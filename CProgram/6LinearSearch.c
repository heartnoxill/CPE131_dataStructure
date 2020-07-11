#include <stdio.h>
#include <stdlib.h>

//A simple approach is to do linear search, i.e
// Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
// If x matches with an element, return the index.
// If x doesn’t match with any of elements, return -1.
// int search(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = search(arr, n, x);
	(result == -1) ? printf("Element is not present in array")
				: printf("Element is present at index %d",
							result);
	return 0;
}
