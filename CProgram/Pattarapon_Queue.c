#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{                   // create struct named Queue
    int front, back, size;      // create variable for the front, the back, and, for the size of the queue (at a certain time)
    int capacity;               // variable for storing capacity of the "Whole queue"
    int* array;                 // declare an array used for storing items
};

struct Queue* createQueue(int capacity){                                    // function for creating a queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));      // create a variable named queue with the size of structed queue
    queue->capacity = capacity;                                             // capacity of the queue will be equal to what user input (to the function)
    queue->front = queue->size = 0;                                         // front and size of queue (at the first) will be equal to zero
    queue->back = capacity-1;                                               // back will be at capacity-1 (because the array starts at zero)
    queue->array = (int*)malloc(queue->capacity * sizeof(int));             // array that will be stored the item will have the size of integer
    return queue;                                                           // return queue pointer
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue){                                            // check if queue is full
    return (queue->size == queue->capacity);                                // condition: size of the queue will equals to user inputted capacity (integer)
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue){                                           // check if queue is empty
    return (queue->size == 0);                                              // condition: size is equals to zero
}

// Function to get front of queue
int front(struct Queue* queue){                     // Get "front of the queue"
    if(isEmpty(queue)){                             // first, check if the queue is empty
        return INT_MIN;                             // return -2147483648 (need to include limits.h)
    }
    return queue->array[queue->front];              // return "item" at the front position
}

// Frunction to get back of queue
int back(struct Queue* queue){                      // Get "back of the queue"
    if(isEmpty(queue)){                             // first, check if the queue is empty
        return INT_MIN;                             // return -2147483648 (need to include limits.h)
    }
    return queue->array[queue->back];               // return "item" at the back position
}


// Function to add an item to the queue
// It changes back and size
void enqueue(struct Queue* queue, int item){        // function used to enqueue (add the item at the back of the queue)
    if(isFull(queue)){                              // first, check if the queue is full
        return;                                     
    }
    queue->back = (queue->back+1)%queue->capacity; // circular queue concept, if "back" is exceed "capacity". Modulus it and it will get back to zero
    queue->array[queue->back] = item;               // item in the array (at back) will be equal to inputted item (from user)
    queue->size = queue->size+1;                    // size of the queue will be increased by 1
    printf("%d enqueued to queue\n",item);          // print "enqueue to queue, "inputted item""
}

// Function to remove an item from queue
// It changes front and size
int dequeue(struct Queue* queue){                   // function used to dequeue (pop the front position of the queue)
    if(isEmpty(queue)){                             // first, check if the queue is empty
        return INT_MIN;                             // return -2147483648 (need to include limits.h)
    }
    int item = queue->array[queue->front];          // set variable item to the front of the array (because it will get dequeued soon)
    queue->front = (queue->front+1)%queue->capacity; // circular queue concept, if "back" is exceed "capacity". Modulus it and it will get back to zero
    queue->size = queue->size-1;                     // after dequeue, size of the queue will decreased by 1
    return item;                                    // return item at the front
}

int main(){
    struct Queue* queue = createQueue(10);                  // create queue with the size of 10

    printf("Front item is %d\n",front(queue)); //empty
    printf("Back item is %d\n", back(queue)); //empty

    enqueue(queue, 10);     // 10 enqueued to queue
    enqueue(queue, 20);     // 20 enqueued to queue
    enqueue(queue, 30);     // 30 enqueued to queue
    enqueue(queue, 40);     // 40 equeued to queue

    printf("%d dequeued from queue\n\n",dequeue(queue)); // 10 dequeued from queue
    printf("Front item is %d\n",front(queue)); // Front item is 20
    printf("Back item is %d\n", back(queue));  // Back item 40
    return 0;
}
