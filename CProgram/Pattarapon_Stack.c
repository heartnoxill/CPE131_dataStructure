#include <stdio.h>
#include <stdlib.h>
//Author Pattarapon Buathong 62070504012

struct stack{       // create struct called stack
    int stackSize;  // size of stack variable, will use to indicate if stack overflow or underflow
    int topStack;   // use to point to the top of the stack
    int *items;     // items in the array (of the stack)
};

int count_stack=0;  // variable used or counting number of elements in the stack

// Initiate new stack structure
struct stack* newStack(int capacity){   // create a new stack function
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack)); // create a new stack (named pt) with the size of stack struct
    pt->stackSize = capacity;                                       // size of stack equals to inputted integer (capacity)
    pt->topStack = -1;                                              // -1 would return to the "back" of the array (in this case, top of the stack)
    pt->items = (int*)malloc(sizeof(int) * capacity);               // item stored in each stack, with the size of integer

    return pt;                                                      // return the stack variable
}

void push(struct stack *pt, int x){                                 // used for adding items in the stack
    printf("Inserting %d\n",x);                                     // print "Inserting "items"" to the screen
    pt->topStack = pt->topStack+1;                                  // variable (topstack) that pointed at the top of the stack would be "plus 1",
                                                                    // which means that next stack will be on the top of a certain stack
    pt->items[pt->topStack] = x;                                    // item at the position "topStack" (now) would be as the user input in the function 
}

// At the "bottom" of stack
int isEmpty(struct stack *pt){                                      // Check if the stack is empty
    return pt->topStack == -1;                                      // return the top of the stack
}

int peekItem(struct stack *pt){                                     // peek to the certain stack that is on the top
    if(!isEmpty(pt)){                                               // if not empty
        return pt->items[pt->topStack];                             // return the item that is now in the topStack array
    }
    else{
        exit(EXIT_FAILURE);                                         // if not, display fail
    }

}

int pop(struct stack *pt){                                          // "pick" the top stack out of the stack
    printf("Removing %d\n",peekItem(pt));                           // print "Removing "item at the top""
    pt->topStack = pt->topStack-1;                                  // topstack will decreased by 1
    return pt->items[pt->topStack];                               // return item that is above of the stack at that time
}

int checkSize(struct stack *pt){                                            // check the size of certain stack
    struct stack *check = (struct stack*)malloc(sizeof(struct stack));      // declare 1 pointer that have same size of our stack in struct stack
    check->topStack = pt->topStack;                                         // pointer of our new variable will be the same as our topstack variable now
    while(check->topStack != -1){                                           // while variable check is still not approaches "empty"
        check->topStack = check->topStack-1;                                // go "down" the stack
        ++count_stack;                                                      // stack count will be plus 1 each time the while loop runs
    }
    printf("Stack size equals to %d\n", count_stack);                       // print out the counted elements in the stack (how many items are there)
    count_stack = 0;                                                        // reset count_stack to zero, in case we want to check size of the stack again
}


int main(){
    struct stack *pt = newStack(5);                                         // create a new stack with the size of 5
    
    push(pt, 1);        // push 1 -> Inserting 1
    push(pt, 2);        // push 2 -> Inserting 2
    push(pt, 3);        // push 3 -> Inserting 3
    push(pt, 4);        // push 4 -> Inserting 4
    checkSize(pt);      // check size (4)
    pop(pt);            // pop top stack -> Removing 4
    checkSize(pt);      // check size (3)
    pop(pt);            // pop top stack -> Removing 3
    checkSize(pt);      // check size (2)
    pop(pt);            // pop top stack -> Removing 2
    checkSize(pt);      // check size (1)


    return 0;

}
