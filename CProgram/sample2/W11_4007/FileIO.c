#include <stdio.h>
#include <stdlib.h>
#include "FileIO.h"

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
