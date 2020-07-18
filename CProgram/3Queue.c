#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front, back, size;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->back = capacity-1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

// Function to get front of queue
int front(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->front];
}

// Frunction to get back of queue
int back(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->back];
}


// Function to add an item to the queue
// It changes back and size
void enqueue(struct Queue* queue, int item){
    if(isFull(queue)){
        return;
    }
    queue->back = (queue->back+1)%queue->capacity; // circular queue
    queue->array[queue->back] = item;
    queue->size = queue->size+1;
    printf("%d enqueued to queue\n",item);
}

// Function to remove an item from queue
// It changes front and size
int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity; // circular queue
    queue->size = queue->size-1;
    return item;
}

int main(){
    struct Queue* queue = createQueue(10);

    printf("Front item is %d (Empty)\n",front(queue)); //empty
    printf("Back item is %d (Empty)\n", back(queue)); //empty

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("Front item is %d\n",front(queue));
    printf("Back item is %d\n", back(queue));
    return 0;
}
