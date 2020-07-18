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

void selectionsort(int* array, int length) {
    int i, j, min_idx; 
    for (i = 0; i < length-1; i++) 
    {
        min_idx = i; 
        for (j = i+1; j < length; j++) 
            if (array[j] < array[min_idx]) 
                min_idx = j;
        swap(array, min_idx, i);
    } 
}

void insertionsort(int* array, int length) {
    int i, key, j; 
    for (i = 1; i < length; i++) 
    { 
        key = array[i]; 
        j = i-1; 
        while (j >= 0 && array[j] > key) 
        { 
            array[j+1] = array[j]; 
            j = j-1; 
        } 
        array[j+1] = key; 
    } 
}

int main() {
    int array[MAX_ARR];
    int count;
    clock_t start_time;

    readFile("data.txt", array, &count);
    start_time = clock();
    selectionsort(array, count);
    printf("selectionsort finished in %.3f seconds\n", (.0f+clock()-start_time)/CLOCKS_PER_SEC );
    writeFile("out_selectionsort.txt", array, count);

    readFile("data.txt", array, &count);
    start_time = clock();
    insertionsort(array, count);
    printf("insertionsort finished in %.3f seconds\n", (.0f+clock()-start_time)/CLOCKS_PER_SEC );
    writeFile("out_insertionsort.txt", array, count);

    printf("\nThe sorted array has just written in output files.\nIt contains %d numbers.\n", count);
    return 0;
}