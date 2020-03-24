#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
};

struct Node *insertNode(int newItem, struct Node *nextNode){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->item = newItem;
    newNode->next = nextNode;
    return(newNode);
}

void printList(struct Node* n){
	while(n != NULL){
		printf("%d\n", n->data);
		n = n->next;
	}
}

int main(){
    struct Node *n = NULL;
    struct Node *first = NULL;
    n = insertNode(9,NULL);
    first = insertNode(19,n);
}
