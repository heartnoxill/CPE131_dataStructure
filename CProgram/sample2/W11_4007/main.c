#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FileIO.h"

#define MAX_ARR 500000

int compareInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int array[MAX_ARR], count, key, index;
    clock_t start_time;
    do
    {
        readFile("data500k.txt", array, &count);
        printf("Enter key for searching data (-1 to END): ");
        scanf("%d", &key);
        rewind(stdin);
        if(key != -1)
        {
            index = linearSearch(array, count, key);
            printf("Linear search finished. The result is %s.\n", index != -1 ? "found" : "not found" );

            qsort(array, count, sizeof(int), compareInt);

            index = binarySearch(array, 0, count-1, key);
            printf("Binary search finished. The result is %s.\n\n", index != -1 ? "found" : "not found" );
        }
    }
    while(key != -1);
    return 1;
}

/* Function will search for a data in the given array with linearSearch algorithm
 * parameters:
 *      array: the array of data
 *      count: the size of the array
 *      key: the key to search
 * return:
 *      index, if there is the data that is equals to key at the given index.
 *      -1, if there is no data in the array with the equals value to key.
 */
int linearSearch(int array[MAX_ARR], int count, int key)
{
    int i;
    for(i=0; i<count; i++)
    {
        if(array[i] == key)
        {
            return key;
        }
    }
    return -1;

}

/* Function will search for a data in the given array with binarySearch algorithm
 * parameters:
 *      array: the array of data
 *      (low, high): the index range of the array.
 *      key: the key to search
 * return:
 *      index, if there is the data that is equals to key at the given index.
 *      -1, if there is no data in the array with the equals value to key.
 */
int binarySearch(int array[MAX_ARR], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if(array[mid] == key)
        {
            return mid;
        }
        if(array[mid] < key)
        {
            low = mid +1;
        }
        if(array[mid] > key)
        {
            high = mid -1;
        }
    }
    return -1;
}
