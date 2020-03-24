#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void appendNode(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* previousNode = (*head_ref);
	new_node -> data = new_data;
	new_node -> next = NULL;
    if((*head_ref) == NULL){
        (*head_ref) = new_node;
    }
    while(previousNode->next != NULL){
        previousNode = previousNode->next;
    }
    previousNode->next = new_node;
}

void pop(struct Node**head_ref, int new_data){
    struct Node* popNode = (*head_ref);
    if((*head_ref) == NULL){
        printf("Exit Program");
        exit(EXIT_FAILURE);
    }
    while(popNode->next != NULL){
        popNode = popNode->next;
    }
}