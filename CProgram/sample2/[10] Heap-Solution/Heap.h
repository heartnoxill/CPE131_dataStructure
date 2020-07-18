#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

void swapArr(int* array, int index1, int index2);
void heapify(int* arr, int arrSize);
void reheapUp(int* arr, int childLoc);
void reheapDown(int* arr, int arrSize, int rootLoc);

#endif // HEAP_ARRAY_H
