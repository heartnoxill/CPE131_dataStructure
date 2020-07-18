#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARR 50000
#define FALSE 0
#define TRUE 0

void readFile(char* filename, int* array, int* count){
    FILE* fp = fopen(filename, "r");
    if(!fp) {
        printf("Can't open file.\n");
        exit(-1);
    }
    else {
        int i = 0;
        while( fscanf(fp, "%d", &array[i]) != EOF ) {
            i++;
        }
        *count = i;
    }
    fclose(fp);
}

void writeFile(char* filename, int* array, int count){
    FILE* fp = fopen(filename, "w");
    if(!fp) {
        printf("Can't open output file.\n");
        exit(-1);
    }
    else {
        int i;
        for(i=0; i<count; i++) {
            fprintf(fp, "%d\n", array[i]);
        }
    }
    fclose(fp);
}

void swap(int* array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void quicksort(int* array, int left, int right) {
    if(right-left > 0) {
        int pivot = array[left];
        int sortLeft = left + 1;
        int sortRight = right;
        while(sortLeft <= sortRight) {
            while(array[sortLeft] < pivot && sortLeft <= right) sortLeft++;
            while(array[sortRight] >= pivot && sortRight >= 0) sortRight--;
            if(sortLeft <= sortRight) {
                swap(array, sortLeft, sortRight);
                sortLeft++;
                sortRight--;
            }
        }
        array[left] = array[sortLeft-1];
        array[sortLeft-1] = pivot;
        if(left<sortRight) quicksort(array, left, sortRight-1);
        if(sortLeft<right) quicksort(array, sortLeft, right);
    }
}

void merge(int* array, int left, int mid, int right) {
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid;
    int* L = (int*) calloc(n1, sizeof(int));
    int* R = (int*) calloc(n2, sizeof(int));
    for (i = 0; i < n1; i++) 
        L[i] = array[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = array[mid + 1 + j]; 
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            array[k] = L[i]; 
            i++; 
        } 
        else
        { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        array[k] = R[j]; 
        j++; 
        k++; 
    }
    free(L);
    free(R);
}

void mergesort(int* array, int left, int right) { 
    if (left < right) 
    { 
        int mid = (left+right) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int array[MAX_ARR];
    int count;
    clock_t start_time;

    readFile("data.txt", array, &count);
    start_time = clock();
    quicksort(array, 0, count-1);
    printf("quicksort finished in %.3f seconds\n", (.0f+clock()-start_time)/CLOCKS_PER_SEC );
    writeFile("out_quicksort.txt", array, count);

    readFile("data.txt", array, &count);
    start_time = clock();
    mergesort(array, 0, count-1);
    printf("mergesort finished in %.3f seconds\n", (.0f+clock()-start_time)/CLOCKS_PER_SEC );
    writeFile("out_mergesort.txt", array, count);

    printf("\nThe sorted array has just written in output files.\nIt contains %d numbers.\n", count);
    return 0;
}