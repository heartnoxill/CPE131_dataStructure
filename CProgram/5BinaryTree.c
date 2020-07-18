#include <stdio.h>
#include <stdlib.h>
#define COUNT 5
//Number sorted binary tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct queue
{
    int front, rear, size;
    struct node* *arr;
};

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct queue* createQueue()
{
    struct queue* newQueue = (struct queue*) malloc(sizeof( struct queue ));
    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));
    return newQueue;
}

//Adds a node to queue
void enqueue(struct queue* queue, struct node *temp){
    queue->arr[queue->rear++] = temp;
    queue->size++;
}

//Deletes a node from queue
struct node *dequeue(struct queue* queue){
    queue->size--;
    return queue->arr[++queue->front];
}

void insertNode(int data) {
    //Create a new node
    struct node *newNode = createNode(data);
    //Check whether tree is empty
    if(root == NULL){
        root = newNode;
        return;
    }
    else {
        //Queue will be used to keep track of nodes of tree level-wise
        struct queue* queue = createQueue();
        //Add root to the queue
        enqueue(queue, root);

        while(1) {
            struct node *node = dequeue(queue);
            //If node has both left and right child, add both the child to queue
            if(node->left != NULL && node->right != NULL) {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else {
                //If node has no left child, make newNode as left child
                if(node->left == NULL) {
                    node->left = newNode;
                    enqueue(queue, node->left);
                }
                //If node has left child but no right child, make newNode as right child
                else {
                    node->right = newNode;
                    enqueue(queue, node->right);
                }
                break;
            }
        }
    }
}

void printBinary(struct node *node) {
    //Check whether tree is empty
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        if(node->left != NULL)
            printBinary(node->left);
            printf("%d ", node->data);
        if(node->right != NULL)
            printBinary(node->right);
        }
    }

    void print2DUtil(struct node *root, int space)
    {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2DUtil(root->right, space);

        // Print current node after space
        // count
        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%d\n", root->data);

        // Process left child
        print2DUtil(root->left, space);
    }

    // Wrapper over print2DUtil()
    void print2D(struct node *root)
    {
       // Pass initial space count as 0
       print2DUtil(root, 0);
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
  printf("\nPrint2D: \n");
  print2D(root);

  return 0;
}
