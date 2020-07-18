#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

void heapify(int* arr, int arrSize);
void reheapUp(int* arr, int childLoc);
void reheapDown(int* arr, int arrSize, int rootLoc);

#endif // HEAP_ARRAY_H
