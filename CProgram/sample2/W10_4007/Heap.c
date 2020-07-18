#include "Heap.h"
#include <stdlib.h>
#include <limits.h>

void swapArr(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int calcLeftChildLoc(int parentLoc) {
    return (2*parentLoc+1);
    /* TODO: return the index of the left child */
}

int calcRightChildLoc(int parentLoc) {
    return (2*parentLoc+2);
    /* TODO: return the index of the right child */
}

int calcParentLoc(int childLoc) {
    return (childLoc - 1) / 2;
}

int hasLeftChild(int arrSize, int loc) {
    return calcLeftChildLoc(loc) <= arrSize - 1;
}

int hasRightChild(int arrSize, int loc) {
    return calcRightChildLoc(loc) <= arrSize - 1;
}

void reheapUp(int* arr, int childLoc){
    int parentLoc;
    if (childLoc != 0)
    {
        parentLoc = calcParentLoc(childLoc);
        if (arr[childLoc]>arr[parentLoc])
        {
            swapArr(arr,childLoc,parentLoc);
            reheapUp(arr,parentLoc);
        }
    }
    /* TODO: implement the reheap up function */
}

void heapify(int* arr, int arrSize){
    int i;
    for(i=0; i<arrSize-1; i++)
    {
        reheapUp(arr,i);
    }
    /* TODO: implement the heapify function */
}

void reheapDown(int* arr, int arrSize, int rootLoc){
    int leftLoc, rightLoc;
    int right, left, root;
    right = INT_MIN;
    root = arr[rootLoc];
    if(hasLeftChild(arrSize, rootLoc)) {
        leftLoc = calcLeftChildLoc(rootLoc);
        left = arr[leftLoc];
        if(hasRightChild(arrSize, rootLoc)) {
            rightLoc = calcRightChildLoc(rootLoc);
            right = arr[rightLoc];
        }
        if(left > right && root < left) {
            swapArr(arr, leftLoc, rootLoc);
            reheapDown(arr, arrSize, leftLoc);
        }
        else if(left <= right && root < right) {
            swapArr(arr, rightLoc, rootLoc);
            reheapDown(arr, arrSize, rightLoc);
        }
    }
}
