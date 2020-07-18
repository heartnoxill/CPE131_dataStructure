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
	// Calculate index of the array to keep the item
	int hashIndex = hashFunction(k);

	// The hashIndex is the position that the data should be stored.
	// However, some keys can generate the same hashIndex values.
	// The collision handling is needed here.
	// TODO: check and change the hashIndex until the array at hashIndex is available.

	// Store the the item in the array.
	strcpy(hashTable[hashIndex].key, k);
	hashTable[hashIndex].score = s;

}

/* Return index of matched record, or -1 otherwise */
int search(char *k)
{
	// Calculate index of the array to keep the item
	int hashIndex = hashFunction(k);

	// Data is sometimes not stored at the hashIndex because of collision handling.
	// TODO: Move the hashIndex to the collect place.

	// Return -1 if not found.
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
