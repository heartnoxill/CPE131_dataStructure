#include <stdio.h>
#include <stdlib.h>
// Author: Pattarapon Buathong 62070504012 //

struct Node{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data){
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node -> data = new_data;
	new_node -> next= (*head_ref);
	(*head_ref) = new_node;
}

void insertItem(struct Node** head_ref, int new_item, int index){
	struct Node* previous_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node* new_one_node = (struct Node*) malloc(sizeof(struct Node));
	previous_node = (*head_ref);
	new_one_node->data = new_item;
	if(index==0){
		printf("Index should started with 1.\t");
	}
	else if(index==1){
		new_one_node->next= (*head_ref);
		(*head_ref) = new_one_node;
	}
	else{
		for(int i=0;i<index-2;i++){
			previous_node = previous_node->next;
		}
	new_one_node->next = previous_node->next;
	previous_node->next = new_one_node;
	}
}

struct Node *previous_node;

void deleteItem(struct Node** head_ref, int index){
	previous_node = (*head_ref);
	if(index==0){
		printf("Index should started with 1.\t");
	}
	else if(index==1){
		(*head_ref) = previous_node->next;
	}
	else{
	for(int i=0;i<index-2;i++){
		previous_node = previous_node->next;
	}
	previous_node->next = previous_node->next->next;
	}
}

void printList(struct Node* n){
	// printList(head);
	while(n != NULL){
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

int main(){
	struct Node* head = NULL;

	push(&head, 4);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	insertItem(&head, 3, 3);
	printList(head);
	insertItem(&head, 5, 0);
	printList(head);
	insertItem(&head, 17, 1);
	printList(head);
	deleteItem(&head, 3);
	printList(head);
	deleteItem(&head, 0);
	printList(head);
	deleteItem(&head, 1);
	printList(head);
	return 0;
}
