// Stack data structure - In linked List
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct nodeStack{
  int data;
  struct stackNode* next;
};

struct nodeStack* newNode(int data){
  struct nodeStack* stackNode = (struct nodeStack*)malloc(sizeof(struct nodeStack));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

int isEmpty(struct nodeStack* root){
  return !root; // check if the stack is empty
}

void push(struct nodeStack** root, int data){
  struct nodeStack* stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
  printf("%d pushed to the stack\n", data);
}

int pop(struct nodeStack** root){
  if(isEmpty(*root)){
    return INT_MIN;
    // printf("Empty");
    // return 0;
  }
  struct nodeStack* temp = *root;
  *root = (*root) -> next;
  int popped = temp->data;
  free(temp); //free memory
  return popped;
}

int peek(struct nodeStack* root){
  if(isEmpty(root)){
    return INT_MIN;
  }
  return root->data;
}

int main(){
  struct nodeStack* root = NULL;
  push(&root, 1);
  push(&root, 2);
  push(&root, 3);
  pop(&root);
  printf("Top element is %d\n", peek(root));
  return 0;
}
