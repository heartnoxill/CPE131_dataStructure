#include <stdio.h>
#include <stdlib.h>
#define COUNT 5     // this variable used in printing the binary tree in 2D dimension
// Author: Pattarapon Buathong 62070504012
// Using node to store the data and linking to another node (child node)
// And using queue to implement what node should come should, in this case, the left most should come first

struct node{                        // structure of a parent node
    int data;                       // data in a node
    struct node *left;              // Left Child node
    struct node *right;             // Right Child node
};

struct node *root = NULL;           // create root node equals to NULL

struct queue{                       // structure of a queue
    int front, rear, size;          // create variable for front, back, and size (at certain time) of a queue
    struct node* *arr;              // variable arr used to store data of the queue
};

struct node* createNode(int data){                                        // function used for creating new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));     // create a new node namesd newNode, with the size of structed "node"
    newNode->data = data;           // data of newNode equals to inputted data variable
    newNode->left = NULL;           // left child node is null
    newNode->right = NULL;          // right child node is null
    return newNode;                 // return newNode variable
}

struct queue* createQueue(){         // function used for creating new queue
    struct queue* newQueue = (struct queue*)malloc(sizeof( struct queue ));     // create a new queue with the size of structed "queue"
    newQueue->front = -1;       // front position will be equals to position -1 ("front" is on the "back")
    newQueue->rear = 0;         // rear position will be equals to position 0
    newQueue->size = 0;         // initial size of queue will be equals to 0
    newQueue->arr = (struct node**)malloc(100 * sizeof( struct node* ));   // used for storing elements in queue
    return newQueue;            // return newQueue variable
}

void enqueue(struct queue* queue, struct node *temp){   // Adds a node to queue
    queue->arr[queue->rear++] = temp;       // arr pointed to newly created rear
    queue->size++;                          // size of the queue increases by 1 (enqueue 1 variable)
}

struct node *dequeue(struct queue* queue){  // Deletes a node from queue
    queue->size--;                          // queue size decreased by 1
    return queue->arr[++queue->front];      // arr pointed to queue that get "pushed" to front by 1
}

/* CONFUSING WARNING!!! (sorry if my English is bad):
    1) If the binary tree is empty, root will be equals to our newly inputted variable (probably interger), let this be the "0-line"
    2) [first line]: Can only contains 2 nodes, the algorithm will check if both child node is NULL (no), then proceed to the next condition,
       which are individually checking left and right nodes. You could clearly see that left is empty, so data will be putted in the left.
       If you add another data, it will get putted in the right, respectively. And, this will satisfies the first condition (left and right != NULL).
       This including adding node->left and node->right to the queue.
    3) [second line]: Now we have 4 nodes. Continuing from 2), node will be equal to dequeued queue (node->left).
       Simply explaining, it will go to left one first [root => [first line]:left => [second line1]: left]. Do the thing. Then, [second line1]:right], then break.
       Now, the "else" really come into the game. Because only node->left is not NULL. So, this will proceed like this...
       [root => [first line]: right => [second line2]:left => [second line2]:right].
    4) And so on.
*/


void insertNode(int data) {
    struct node *newNode = createNode(data);    // Create a new node
    if(root == NULL){                           // Check whether tree is empty
        root = newNode;                         // if the queue is empty, root will equals to newNode (first inputted variable)
        return;                                 // return root
    }
    else {
        struct queue* queue = createQueue(); // Queue will be used to keep track of nodes of tree level-wise (initialized every break)
        enqueue(queue, root);                // Add root to the queue

        while(1) {                                              // While true, do...
            struct node *node = dequeue(queue);                 // create a node equals to dequeued queue
            if(node->left != NULL && node->right != NULL) {     // If node has both left and right child, add both the child to queue
                enqueue(queue, node->left);                     // put node->left to the queue
                enqueue(queue, node->right);                    // node node->right to the queue, after node->left
            }
            else {
                if(node->left == NULL) {            // If node has no left child, make newNode as left child
                    node->left = newNode;           // node->left will equals to our newNode (with inputted data)
                    enqueue(queue, node->left);     // put node->left to the queue
                }
                else {                              // If node has left child but no right child, make newNode as right child
                    node->right = newNode;          // node->right will equals to our newNode (with inputted data)
                    enqueue(queue, node->right);    // put node->right to the queue
                }
                break;                              // break the loop
            }
        }
    }
}

void printBinary(struct node *node) {
    if(root == NULL){                           // Check whether tree is empty
        printf("Tree is empty\n");              // print "Tree is empty"
        return;                                 // return root
    }
    else {                                      // else condition
        if(node->left != NULL)                  // if node-> left not equals to NULL
            printBinary(node->left);            // recursive the function, with node->left
            printf("%d ", node->data);          // print data in the node
        if(node->right != NULL)                 // if node->right not equals to NULL
            printBinary(node->right);           // recursive the function, with node->right
        }
    }

    void print2DAlgo(struct node *root, int space)  // Function that used to print the binary tree as 2D Dimension, horizontally printed
    {
        if (root == NULL)                   // if root is equals to NULL
            return;                         // return root

        space += COUNT;                     // Increase distance between levels
        print2DAlgo(root->right, space);    // Process right child first

        printf("\n");                       // new line
        for (int i = COUNT; i < space; i++) // for loop, start from defined COUNT (5) to space, iterate by 1 per loop
            printf(" ");                    // print blank space
        printf("%d\n", root->data);         // Print current node after space count

        print2DAlgo(root->left, space);     // Process left child
    }

    void print2D(struct node *root)         // Wrapper over print2DAlgo()
    {
       print2DAlgo(root, 0);                // Pass initial space count as 0
    }

int main(){

  insertNode(1);
  printf("\nBinary tree after insertion: \n");
  printBinary(root);

  insertNode(2);
  insertNode(3);
  //2 will become left child and 3 will become right child of root node 1
  printf("\nBinary tree after insertion: \n");
  printBinary(root);

  insertNode(4);
  insertNode(5);
  //4 will become left child and 5 will become right child of root node 2
  printf("\nBinary tree after insertion: \n");
  printBinary(root);

  insertNode(6);
  insertNode(7);
  //6 will become left child and 7 will become right child of root node 3
  printf("\nBinary tree after insertion: \n");
  printBinary(root);

  printf("\n\nPrint2D: \n");
  print2D(root);

  return 0;
}
