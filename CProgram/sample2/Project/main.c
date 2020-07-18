#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct input
{
    char day[100],day1[100];
    char month[100],month1[100];
    char year[100],year1[100];
    char name[100];
    char dates[100];
    char sort[100];
    int sortt;
} input;
input data[100],swap[5];

int count;
void readFile(char* filename)
{

    char array[100];
    char *token1;
    FILE* fp = fopen(filename, "r");
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
            token1 = strtok(array,",");
            strupr(token1);
            strcpy(data[i].name,token1);
            token1 = strtok(NULL,",");
            strupr(token1);
            strcpy(data[i].dates,token1);
            token1 = strtok(NULL,",");
            strcpy(data[i].day1,token1);
            strcpy(data[i].day,token1);
            token1 = strtok(NULL,",");
            strcpy(data[i].month1,token1);
            strcpy(data[i].month,token1);
            token1 = strtok(NULL,",");
            strcpy(data[i].year1,token1);
            strcpy(data[i].year,token1);
            strcpy(data[i].sort,strcat(data[i].year1,strcat(data[i].month1,data[i].day1)));
            data[i].sortt = atoi(data[i].sort);
            i++;
        }
        count = i;
    }
    fclose(fp);
}

void writeFile(char* filename,char e[100],char f[100],char b[100],char c[100],char d[100])
{
    int array;
    FILE* fp = fopen(filename, "a");
    if(!fp)
    {
        printf("Can't open output file.\n");
        exit(-1);
    }
    else
    {
        fprintf(fp, "%s,%s,%s,%s,%s\n",e,f,b,c,d);
    }
    fclose(fp);
}

void writeFile1(char* filename)
{
    int array;
    FILE* fp = fopen(filename, "w+");
    fclose(fp);
}

void Prstr()
{
    int i;
    for(i=0; i<count; i++)
    {
        printf("%s/%s/%s Name : %s Address : %s\n",data[i].day,data[i].month,data[i].year,data[i].name,data[i].dates);
    }
}

void swapp()
{
    int i,j;
    char *token1;
    readFile("data.txt");
    for(i=0; i<count+1; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(data[j].sortt > data[j+1].sortt)
            {
                swap[0] = data[j];
                data[j] = data[j+1];
                data[j+1] = swap[0];
            }
        }
    }
}

void crnode()
{
    int i;
    printf("[SEND]->");
    for(i=0; i<count; i++)
    {
        printf("%s->",data[i].name);
    }
    printf("NULL\n");
}


int main()
{
    char str_1[20],str_2[20];
    int a,i,j,k,x;
    char e[100],f[100],b[100],c[100],d[100];
    do
    {
        swapp();
        printf("<< Mode of transport >>\n");
        printf("1) Show list\n");
        printf("2) Insert list\n");
        printf("3) Delete order\n");
        printf("4) Search name:\n");
        printf("Choose your answer or exit(-1) : ");
        scanf("%d",&a);
        fflush(stdin);

        if(a == 1)
        {
            swapp();
            crnode();
            Prstr();
            printf("You want exit(-1):");
            scanf("%d",&k);
        }

        if(a == 2)
        {
            i=0;
            swapp();
            printf("Name: ");
            scanf("%s",e);
            strupr(e);
            printf("Address: ");
            scanf("%s",f);
            strupr(f);
            do
            {
                printf("Day: ");
                scanf("%s",&b);
                x = atoi(b);
                printf("%d\n",x);
                if(x<0 || x>31)
                {
                    printf("Try again\n");
                    continue;
                }
                else
                    break;
            }
            while(1);

            do
            {
                printf("Month: ");
                scanf("%s",&c);
                x = atoi(c);
                if(x<0 || x>12)
                {
                    printf("Try again\n");
                    continue;
                }
                else
                    break;
            }
            while(1);

            do
            {
                printf("Year: ");
                scanf("%s",&d);
                x = atoi(d);
                if(x<2000 || x>3000)
                {
                    printf("Try again\n");
                    continue;
                }
                else
                    break;
            }
            while(1);

            printf("%s %s %s %s %s\n",e,f,b,c,d);
            writeFile("data.txt",e,f,b,c,d);
            printf("Save file finish\n");
            printf("You want exit(-1):");
            scanf("%d",&k);
        }

        if(a == 3)
        {
            swapp();
            printf("Delete name: ");
            fscanf(stdin,"%s",str_1);
            sscanf(str_1,"%s",str_2);
            strupr(str_2);

            for(i=0; i<count; i++)
            {
                if(strcmp(data[i].name,str_2)==0)
                {
                    j = i;
                }
            }

            writeFile1("data.txt");

            for(i=0; i<j; i++)
            {
                strcpy(e,data[i].name);
                strcpy(f,data[i].dates);
                strcpy(b,data[i].day);
                strcpy(c,data[i].month);
                strcpy(d,data[i].year);
                writeFile("data.txt",e,f,b,c,d);
            }

            for(i=j+1; i<count; i++)
            {
                strcpy(e,data[i].name);
                strcpy(f,data[i].dates);
                strcpy(b,data[i].day);
                strcpy(c,data[i].month);
                strcpy(d,data[i].year);
                writeFile("data.txt",e,f,b,c,d);
            }

            printf("Delete name finish\n");
            printf("You want exit(-1):");
            scanf("%d",&k);
        }

        if(a == 4)
        {
            swapp();
            char key[100];

            do
            {
                j=0;
                printf("Search your name: ");
                scanf("%s",key);
                strupr(key);

                for(i=0; i<count; i++)
                {
                    if(strcmp(key,data[i].name) == 0)
                    {
                        printf("Name: %s\n",data[i].name);
                        printf("Address: %s\n",data[i].dates);
                        printf("Date: %s/%s/%s\n",data[i].day,data[i].month,data[i].year);
                        j++;
                    }
                }

                if(j == 0)
                {
                    printf("Not found name\n");
                }

            }
            while(j == 0);

            printf("You want exit(-1):");
            scanf("%d",&k);
        }
        else
            continue;
    }
    while(k != -1 && a != -1);
}
