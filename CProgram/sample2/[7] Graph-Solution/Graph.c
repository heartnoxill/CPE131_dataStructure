#include "Graph.h"

GRAPH * create_graph(int node_count)
{
    /* 1. Allocate memory for graph */
    GRAPH * graph = (GRAPH *) calloc (1, sizeof(GRAPH));
    graph->node_count = node_count;
    /* 2. Create nodes */
    int i, j;
    for(i=0; i<node_count; i++)
    {
        graph->node_labels[i] = 'A'+i;
        printf("Create node: %c\n", graph->node_labels[i]);
    }
    /* 3. Create edges */
    for(i=0; i<node_count-1; i++)
    {
        for(j=i+1; j<node_count; j++)
        {
            char temp;
            printf("Create edge between %c and %c? (y/n) : ", graph->node_labels[i], graph->node_labels[j]);
            fflush(stdin);
            scanf("%c", &temp);
            if(temp == 'y' || temp == 'Y')
            {
                graph->adjacency[i][j] = graph->adjacency[j][i] = 1;
            }
        }
    }
    return graph;
}

void add_node(GRAPH * graph)
{
    int i, node_count = graph->node_count;
    /* 1. Label the new node and add it to array of nodes */
    graph->node_labels[node_count] = graph->node_labels[node_count - 1] + 1;
    /* 2. Ask for edges from the node to every other node and set the value in adjacency matrix */
    for(i=0; i<node_count; i++)
    {
        char temp;
        printf("Create edge between %c and %c? (y/n) : ", graph->node_labels[i], graph->node_labels[node_count]);
        fflush(stdin);
        scanf("%c", &temp);
        if(temp == 'y' || temp == 'Y')
        {
            graph->adjacency[i][node_count] = graph->adjacency[node_count][i] = 1;
        }
    }
    /* 3. Increase node count */
    graph->node_count = graph->node_count + 1;
}

void delete_node(GRAPH * graph, char node_label)
{
    /* 1. Initialize removingIndex to a negative value*/
    int removingIndex = -1;
    /* 2. Search for removing node, then set removingIndex by its index */
    int i, j;
    for(i=0; i<graph->node_count; i++)
    {
        if (graph->node_labels[i] == node_label)
        {
            removingIndex = i;
        }
    }
    /* 3. If removingIndex is not negative number, then remove the node from graph */
    if(removingIndex >= 0)
    {
        /* 3.1 Remove all edges, */
        for (i=removingIndex; i<graph->node_count-1; i++) {
            for (j=0; j<graph->node_count; j++) {
                graph->adjacency[i][j] = graph->adjacency[i+1][j];
            }
        }
        for (i=removingIndex; i<graph->node_count-1; i++) {
            for (j=0; j<graph->node_count; j++) {
                graph->adjacency[j][i] = graph->adjacency[j+1][i];
            }
        }

        /* 3.2 Remove the node from the array of nodes */
        for(i = removingIndex; i<graph->node_count; i++)
        {
            graph->node_labels[i] = graph->node_labels[i+1];
        }
        /* 3.3 Decrease count */
        graph->node_count = graph->node_count - 1;
    }
}

void display_adjacent(GRAPH * graph)
{
    int i, j;
    printf("   ");
    for(i=0; i<graph->node_count; i++)
    {
        printf("%c ", graph->node_labels[i]);
    }
    printf("\n");
    for(i=0; i<graph->node_count; i++)
    {
        printf("%c: ", graph->node_labels[i]);
        for(j=0; j<graph->node_count; j++)
        {
            printf("%d ", graph->adjacency[i][j]);
        }
        printf("\n");
    }
}
