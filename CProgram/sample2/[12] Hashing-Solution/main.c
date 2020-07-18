#include <stdio.h>
#include <string.h>

#define DICT_SIZE 100

/* Record storing name and score */
typedef struct{
	char key[20];
	int score;
} DICT;

/* Set hash_table size double of dictionary size */
DICT hashTable[DICT_SIZE];

void insert(char *, int );
int search(char *);

int hashFunction(char* key) {
	int i;
	int sum = 0;
	for(i=0; i<strlen(key); i++) {
		sum += (key[i]-'A');
	}
	return sum % DICT_SIZE;
}

void insert(char *k, int s)
{
	int hashIndex = hashFunction(k);
	while(hashTable[hashIndex].score != -1) {
		hashIndex = (hashIndex + 1) % DICT_SIZE;
	}
	strcpy(hashTable[hashIndex].key, k);
	hashTable[hashIndex].score = s;
}

/* Return index of matched record, or -1 otherwise */
int search(char *k)
{
	int hashIndex = hashFunction(k);
	while(hashTable[hashIndex].score != -1) {
		if (strcmp(hashTable[hashIndex].key, k) == 0) {
			return hashIndex;
		} else {
			hashIndex = (hashIndex + 1) % DICT_SIZE;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	int i;
	char fname[20] = "scores.csv";
	FILE *fp;
	
	fp = fopen(fname, "r");
	
	if(!fp)
	{
		printf("File not found\n");
		return 0;
	}
	
	/* Initialize the hash table */
	for(i=0; i < DICT_SIZE; i++)
		hashTable[i].score = -1;
		
	/* Read input from file */
	while(!feof(fp))
	{
		char key[20];
		int score;
		
		fscanf(fp, "%[^,],%d\n", key, &score);
		insert(key, score);
	}
	
	fclose(fp);
	char name2[20];
	int score;
	printf("Insert name :");
		gets(name2);
		printf("score : ");
		scanf("%d",&score);
		insert(name2,score);
		
	/* Show the hash table */
	for(i=0; i<DICT_SIZE; i++)
		if(hashTable[i].score != -1)
			printf("index %d, key %s, score %d\n", i, hashTable[i].key, hashTable[i].score); 
			
	while(1)
	{
		char name[20];
		int idx;
		
		printf("Enter a student name to search ('quit' to exit): ");
		gets(name);
		
    	 		
		if(!strcmp(name, "quit"))
			break;
	
		idx = search(name); 
		
		if(idx == -1)
			printf("	No match found..\n\n");
		else
			printf("	%s gets the score %d ..\n\n", name, hashTable[idx].score);			
	}
	
	return 0;
}

