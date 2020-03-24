#include <stdio.h>
#include <stdlib.h>
//Author: Pattarapon Buathong 62070504012

int stackNum, i, j, count;  // global these variable

struct stack{               // create stack 
  int sizeStack;            // create variable that will refer to size of stack
  int topStack;             // create variable that will refer to top of the stack
  int *items;               // create variable that will hold element
};

struct stack* newStack(int capacity){                                 // create new stack with the size of "capacity"
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));   // create stack named "pt" with the size of structed stack
    pt->sizeStack = capacity;                                         // capacity of the stack equals to inputted "capacity"
    pt->topStack = -1;                                                // top stack is at index -1 (at the back(top) of the stack)
    pt->items = (int*)malloc(sizeof(int) * capacity);                 // call by reference: store stack with size of int
    return pt;                                                        // return pt pointer 
}

void push(struct stack *pt, int pushNum){     // function that put the element in the stack
    pt->topStack = pt->topStack+1;            // top of the stack will increase by 1, after input new element to the stack
    pt->items[pt->topStack] = pushNum;        // item position will be at the top stack with the value of inputted "pushNum"
}

int pop(struct stack *pt){                    // function that take out the element from the stack
    printf("%d",pt->items[pt->topStack]);     // print item at the position of top stack at that moment to the screen
    pt->topStack = pt->topStack-1;            // top stack will decrease by 1, because we remove the top of the stack
}

int binaryModulus(struct stack *pt, int divideNumber){  // function that refer to using modulo to divide decimal number, get it remainder, arrange it as binary number
  count = 0;                                            // initialize the count variable as zero (reset every different number)
  while(divideNumber!=0){                               // while divideNumber is not equal to zero, do...
    int stackNum = divideNumber%2;                      // modulus the divideNumber variable, the result will be stored in stackNum variable
    push(pt, stackNum);                                 // push the stackNum variable to the pt stack
    divideNumber = divideNumber/2;                      // divide the variable with 2
    count++;                                            // iterate count variable by 1
  }
}

int popLoop(struct stack *pt){    // used for popping the number in the stack (displaying binary number of each number)
  for(i=0;i<count;i++){           // for loop from 0 to count-1 (this is why we need to initialize count to zero everytime)
    pop(pt);                      // use the function "pop" to take out the binary number stored in the stack
  }
}

int generateBinary(struct stack *pt, int inputNumber){    // this function used to loop and print the inputted decimal number
  for(j=1;j<=inputNumber;j++){                            // for loop, starts from 1 (first number) to inputted number (stored in inputNumber variable)
    binaryModulus(pt, j);                                 // use the function "binaryModulus" for each number "j" iterates
    popLoop(pt);                                          // take out (print) the binary number from the stack
    printf(" ");                                          // print the space 
  }
}

int main(){                                       // main function
  struct stack *pt = newStack(100);               // create new stack with size of 100
  int capa;                                       // variable that will store user's input
  printf("Input number: ");                       // print "Input number: "
  scanf("%d", &capa);                             // receive user input and store in capa variable
  generateBinary(pt, capa);                       //1 10 11 100 101
  return 0;                                       // return void
}
