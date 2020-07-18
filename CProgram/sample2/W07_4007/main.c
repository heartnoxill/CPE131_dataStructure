#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main()
{
    int choice = 0;
    GRAPH * graph;
    int n;
    printf("How many node in graph? ");
    fflush(stdin);
    scanf("%d", &n);
    graph = create_graph(n);
    while(choice != 4)
    {
        printf("\n");
        printf("1. Display adjacency\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        if (choice == 1)
        {
            display_adjacent(graph);
        }
        else if(choice == 2)
        {
            add_node(graph);
        }
        else if (choice == 3)
        {
            char label;
            printf("Enter node name: ");
            fflush(stdin);
            scanf("%c", &label);
            delete_node(graph, label);
        }
    }
    printf("Program exited.\n");
    return 0;
}
