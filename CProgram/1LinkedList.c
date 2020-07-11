// Linked list - printList - pushFront - insertAfter - appendEnd - deleteNode
#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next; // next is to link the next node
};

void printList(struct Node* n){
  while(n != NULL){
    printf(" %d ", n->data);
    n = n->next;
  }
  printf("\n");
}

void pushFront(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
  if(prev_node==NULL){
    printf("Previous node is NULL");
    return;
  }
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void appendEnd(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if(*head_ref == NULL){
    *head_ref = new_node;
    return;
  }
  while(last->next!=NULL){
    last = last->next; // Traverse till the last Node
  }
  last->next = new_node;
  return;
}

void deleteNode(struct Node** head_ref, int key){
  struct Node* temp = *head_ref, *prev;
  if(temp!=NULL && temp->data==key){  //If head node hold the key
    *head_ref = temp->next;
    free(temp); //free the old head
    return;
  }
  while(temp!=NULL && temp->data!=key){ //IF not
    prev = temp;
    temp = temp->next;
  }
  if(temp==NULL) return; //no key
  prev->next = temp->next;
  free(temp); //free memory
}

int main(){
    struct Node* head = NULL;
    appendEnd(&head, 3);
    pushFront(&head, 2);
    pushFront(&head, 1);
    appendEnd(&head, 4);
    printList(head);
    insertAfter(head->next, 21); // Insert after "2"
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}
