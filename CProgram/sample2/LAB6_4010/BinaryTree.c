#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TREE * createTree()
{
    TREE * t = (TREE*) calloc(1, sizeof(TREE));
    return t;
}

void inorderTraversal(NODETREE * node)
{
    if(node->leftChild!=NULL)
    {
        inorderTraversal(node->leftChild);
    }
    printf("%s",node->data);
    if(node->rightChild!=NULL)
    {
        inorderTraversal(node->rightChild);
    }
    /* Enter your code here */
}

void preorderTraversal(NODETREE * node)
{
    printf("%s",node->data);
    if(node->leftChild!=NULL)
    {
        inorderTraversal(node->leftChild);
    }
    if(node->rightChild!=NULL)
    {
        inorderTraversal(node->rightChild);
    }
    /* Enter your code here */
}

void postorderTraversal(NODETREE * node)
{
    if(node->leftChild!=NULL)
    {
        inorderTraversal(node->leftChild);
    }
    if(node->rightChild!=NULL)
    {
        inorderTraversal(node->rightChild);
    }
    printf("%s",node->data);
    /* Enter your code here */
}

void insertDataRecursive(NODETREE* node, char data[10])
{
    strcpy(node->data, data);
    double number;
    if(sscanf(data, "%lf", &number) != 1) // if not the number
    {
        char buffer[200], leftData[10], rightData[10];

        printf("Enter left of %s : ", data);
        fgets(buffer, 200, stdin);
        sscanf(buffer, "%s", leftData);
        NODETREE* newLeftNode = (NODETREE*) calloc(1, sizeof(NODETREE));
        node->leftChild = newLeftNode;
        insertDataRecursive(newLeftNode, leftData);

        printf("Enter right of %s : ", data);
        fgets(buffer, 200, stdin);
        sscanf(buffer, "%s", rightData);
        NODETREE* newRightNode = (NODETREE*) calloc(1, sizeof(NODETREE));
        node->rightChild = newRightNode;
        insertDataRecursive(newRightNode, rightData);
    }
}

void insertData(TREE* t)
{
    char buffer[200], data[10];
    NODETREE* node = (NODETREE*) calloc(1, sizeof(NODETREE));
    t->root = node;
    printf("Enter the root node data: ");
    fgets(buffer, 200, stdin);
    sscanf(buffer, "%s", data);
    insertDataRecursive(node, data);
}

void destroyTreeRecursive(NODETREE * node)
{
    if(hasLeftChild(node))
    {
        destroyTreeRecursive(node->leftChild);
    }
    if(hasRightChild(node))
    {
        destroyTreeRecursive(node->rightChild);
    }
    if(node!=NULL)
    {
        free(node);
    }
}
void destroyTree(TREE* t)
{
    destroyTreeRecursive(t->root);
}
int hasLeftChild(NODETREE * node)
{
    return (node != NULL) && (node->leftChild != NULL);
}
int hasRightChild(NODETREE * node)
{
    return (node != NULL) && (node->rightChild != NULL);
}
