#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"
#include "Heap.h"

#define MAX_ARR 50000

void heapsort(int* arr, int count) {
    heapify(arr, count);
    int i;
    for (i=count-1; i>=1; i--) {
        swapArr(arr, 0, i);
        reheapDown(arr, i, 0);
    }
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
