#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"
#include "Heap.h"

#define MAX_ARR 50000

void heapsort(int* arr, int count) {
    int i;
    heapify(arr,count);
    for (i=count-1; i>0; i--)
    {
        swapArr(arr,0,i);
        reheapDown(arr,i,0);
    }
    /* add your code here */
}

int main() {
    int array[MAX_ARR];
    int count;
    readFile("data.txt", array, &count);
    heapsort(array, count);
    writeFile("outdata.txt", array, count);
    printf("The sorted array has just written in output file.\nIt contains %d numbers.\n", count);
    return 1;
}
