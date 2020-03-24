#include <stdio.h>
#include <stdlib.h>

struct Node{
  int item;
  struct Node *next;
};

struct Node *newNode;
struct Node *head;
struct Node *curr;
struct Node *prev;

struct Node *insertNode(int newItem, struct Node *nextNode){
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->item = newItem;
  newNode->next = nextNode;
  return(newNode);
}

void add(int newItem){
  if(head==NULL){
    newNode = insertNode(newItem, NULL);
  }
  else{
    newNode = insertNode(newItem, head);
  }
  head = newNode;
}

void showdata(){
  curr = head;
  while(curr!=NULL){
    printf("%d ", curr->item);
    curr = curr->next;
  }
  printf("\n");
}

int main(){
  add(9);
  printf("add 9: ");
  showdata();
  add(15);
  printf("add 15: ");
  showdata();
  return 0;
}
