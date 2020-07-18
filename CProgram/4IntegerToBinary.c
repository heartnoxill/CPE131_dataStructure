#include <stdio.h>
#include <stdlib.h>
//Author: Pattarapon Buathong 62070504012
//Stack implementation for converting integer number to binary number
int stackNum, i, j, count;

struct stack{
  int sizeStack;
  int topStack;
  int *items;
};

struct stack* newStack(int capacity){
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->sizeStack = capacity;
    pt->topStack = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
    return pt;
}

void push(struct stack *pt, int pushNum){
    pt->topStack = pt->topStack+1;
    pt->items[pt->topStack] = pushNum;
}

int pop(struct stack *pt){
    printf("%d",pt->items[pt->topStack]);
    pt->topStack = pt->topStack-1;
}

int binaryModulus(struct stack *pt, int divideNumber){
  count = 0;
  while(divideNumber!=0){
    int stackNum = divideNumber%2;
    push(pt, stackNum);
    divideNumber = divideNumber/2;
    count++;
  }
}

int popLoop(struct stack *pt){
  for(i=0;i<count;i++){
    pop(pt);
  }
}

int generateBinary(struct stack *pt, int inputNumber){
  for(j=1;j<=inputNumber;j++){ //starts from 1
    binaryModulus(pt, j);
    popLoop(pt);
    printf(" ");
  }
}

int main(){
  struct stack *pt = newStack(100);
  //ref
  int capa;
  printf("Input number: ");
  scanf("%d", &capa);
  generateBinary(pt, capa); //1 10 11 100 101
  return 0;
}
