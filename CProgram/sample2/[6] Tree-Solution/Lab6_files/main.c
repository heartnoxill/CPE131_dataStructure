#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    TREE* tree = createTree();
    insertData(tree);

    printf("\nInorder Traversal: ");
    inorderTraversal(tree->root);

    printf("\nPreorder Traversal: ");
    preorderTraversal(tree->root);

    printf("\nPreorder Traversal: ");
    postorderTraversal(tree->root);

    destroyTree(tree);
    printf("\n");
    return 0;
}
