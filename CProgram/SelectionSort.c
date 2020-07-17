// Selection Sort iterative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct lnode {
 int data;
 struct lnode *next;
} *head, *visit;

/* add a new entry to the linked list */
void llist_add(struct lnode **q, int num);
/* preform a selection sort on the linked list */
void llist_selection_sort(void);
/* print the entire linked list */
void llist_print(void);

int main(void) {
 /* linked list */
 struct lnode *newnode = NULL;
 int i = 0; /* a general counter */

 /* load some random values into the linked list */
 for(i = 0; i < MAX; i++) {
  llist_add(&newnode, (rand() % 100));
 }

 head = newnode;
 printf("Before selection sort:\n");
 llist_print();
 printf("After  selection sort:\n");
 llist_selection_sort();
 llist_print();

 return 0;
}

/* adds a node at the end of a linked list */
void llist_add(struct lnode **q, int num) {
 struct lnode *temp; 
 
 temp = *q;

 /* if the list is empty, create first node */
 if(*q == NULL) {
  *q = malloc(sizeof(struct lnode));
   temp = *q;
 } else {
  /* go to last node */
  while(temp->next != NULL)
   temp = temp->next;

   /* add node at the end */
   temp->next = malloc(sizeof(struct lnode));
   temp = temp->next;
 }

 /* assign data to the last node */
 temp->data = num;
 temp->next = NULL;
}

/* print the entire linked list */
void llist_print(void) {
 visit = head;

 /* traverse the entire linked list */
 while(visit != NULL) {
  printf("%d ", visit->data);
  visit = visit->next;
 }
 printf("\n");
}

void llist_selection_sort(void) {
 struct lnode *a = NULL;
 struct lnode *b = NULL;
 struct lnode *c = NULL;
 struct lnode *d = NULL;
 struct lnode *tmp = NULL;

 a = c = head;
 while(a->next != NULL) {
  d = b = a->next;
  while(b != NULL) {
   if(a->data > b->data) {
    /* neighboring linked list node */
    if(a->next == b) { 
     if(a == head) {
      a->next = b->next;
      b->next = a;
      tmp = a;
      a = b;
      b = tmp;
      head = a;
      c = a;
      d = b;
      b = b->next;
     } else {
      a->next = b->next;
      b->next = a;
      c->next = b;
      tmp = a;
      a = b;
      b = tmp;
      d = b;
      b = b->next;
     }
    } else {
     if(a == head) {
      tmp = b->next;
      b->next = a->next;
      a->next = tmp;
      d->next = a;
      tmp = a;
      a = b;
      b = tmp;
      d = b;
      b = b->next;
      head = a;
    } else {
     tmp = b->next;
     b->next = a->next;
     a->next = tmp;
     c->next = b;
     d->next = a;
     tmp = a;
     a = b;
     b = tmp;
     d = b;
     b = b->next;
    }
   }
  } else {
   d = b;
   b = b->next;
  }
 }
  c = a;
  a = a->next;
 }
}
