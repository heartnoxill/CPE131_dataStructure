#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _nodetree {
    char data[10];
    struct _nodetree * leftChild;
    struct _nodetree * rightChild;
} NODETREE;

typedef struct {
    NODETREE * root;
} TREE;

TREE * createTree();
void insertData(TREE* t);
void inorderTraversal(NODETREE * node);
void preorderTraversal(NODETREE * node);
void postorderTraversal(NODETREE * node);
void destroyTree(TREE* t);
int hasLeftChild(NODETREE * node);
int hasRightChild(NODETREE * node);


#endif // BINARY_TREE_H
