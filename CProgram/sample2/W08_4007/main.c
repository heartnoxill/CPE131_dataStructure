#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ARR 50000
#define FALSE 0
#define TRUE 0

typedef struct datanaja
{
    char name[100];
    char surname[100];
    int code;
} DATA;


void readFile(char* filename, int* array, int* count)
{
    FILE* fp = fopen(filename, "r");
    if(!fp)
    {
        printf("Can't open file.\n");
        exit(-1);
    }
    else
    {
        int i = 0;
        while( fscanf(fp, "%d", &array[i]) != EOF )
        {
            i++;
        }
        *count = i;
    }
    fclose(fp);
}

void writeFile(char* filename, int* array, int count)
{
    FILE* fp = fopen(filename, "w");
    if(!fp)
    {
        printf("Can't open output file.\n");
        exit(-1);
    }
    else
    {
        int i;
        for(i=0; i<count; i++)
        {
            fprintf(fp, "%d\n", array[i]);
        }
    }
    fclose(fp);
}

void swap(int* array, int index1, int index2)
{
    int *token;
    token = array[index2];
    array[index2] = array[index1];
    array[index1] = token;
    // TODO
}

void selectionsort(int* array, int length)
{
    int i,j;
    int min;
    for(i=0; i<length-1; i++)
    {
        min = i;
        for(j=i+1; j<length; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }

        }
        swap(array,min,i);
    }
    // TODO
}

void insertionsort(int* array, int length)
{
    int i,j;
    int key;
    for(i=1; i<length-1; i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
    // TODO
}

void codename()
{
    struct datanaja data[100],am;
    int i,count,j;
    int key;
    char array[100],*token;
    FILE* fp = fopen("challenge.csv", "r");
    if(!fp)
    {
        printf("Can't open file.\n");
        exit(-1);
    }
    else
    {
        int i = 0;
        while( fscanf(fp, "%s", array) != EOF )
        {
            if(i>0)
            {
                token = strtok(array, ",");
                strcpy(data[i].name,token);

                token = strtok(NULL,",");
                strcpy(data[i].surname,token);

                token = strtok(NULL,",");
                data[i].code = atoi(token);
            }
                i++;

        }
        count = i;
    }
    fclose(fp);

    for(i=1; i<count; i++)
    {
        key = data[i].code;
        am = data[i];
        j = i-1;
        while(j>=0 && data[j].code>key)
        {
            data[j+1] = data[j];
            j = j-1;
        }
        data[j+1] = am;

    }

    fp = fopen("challenge.csv", "w");
    if(!fp)
    {
        printf("Can't open output file.\n");
        exit(-1);
    }
    else
    {
        int i;
        fprintf(fp,"Name,Surname,secret_code\n");
        for(i=count-1; i>0; i--)
        {
            fprintf(fp, "%s,%s,%d\n", data[i].name,data[i].surname,data[i].code);
        }
    }
    fclose(fp);

}

int main()
{
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


    codename();
    printf("\nThe sorted array has just written in output files.\nIt contains %d numbers.\n", count);
    return 0;
}
