#include <stdio.h>
#include <stdlib.h>
//Author Pattarapon Buathong 62070504012

struct stack{
    int stackSize;
    int topStack;
    int *items;
};

int count_stack=0;

// Initiate new stack structure
struct stack* newStack(int capacity){
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->stackSize = capacity;
    pt->topStack = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

void push(struct stack *pt, int x){
    printf("Inserting %d\n",x);
    pt->topStack = pt->topStack+1;
    pt->items[pt->topStack] = x;
}

// At the "bottom" of stack
int isEmpty(struct stack *pt){
    return pt->topStack == -1;
}

int peekItem(struct stack *pt){
    if(!isEmpty(pt)){
        return pt->items[pt->topStack];
    }
    else{
        exit(EXIT_FAILURE);
    }
}

int pop(struct stack *pt){
    printf("Removing %d\n",peekItem(pt));
    pt->topStack = pt->topStack-1;
    return pt->items[pt->topStack--];
}

int checkSize(struct stack *pt){
    struct stack *check = (struct stack*)malloc(sizeof(struct stack));
    check->topStack = pt->topStack;
    while(check->topStack != -1){
        check->topStack = check->topStack-1;
        count_stack++;
    }
    printf("Stack size equals to %d\n", count_stack);
    count_stack = 0;
}


int main(){
    struct stack *pt = newStack(5);

    push(pt, 1);
    push(pt, 2);
    push(pt, 3);
    push(pt, 4);
    checkSize(pt);
    pop(pt);
    checkSize(pt);
    pop(pt);
    checkSize(pt);
    pop(pt);
    checkSize(pt);


    return 0;

}
