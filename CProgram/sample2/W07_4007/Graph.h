#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 20

typedef struct _graph {
    char node_labels[MAX_NODE];
    int adjacency[MAX_NODE][MAX_NODE];
    int node_count;
} GRAPH;

GRAPH * create_graph();
void add_node(GRAPH * graph);
void delete_node(GRAPH * graph, char node_label);
void display_adjacent(GRAPH * graph);

#endif // GRAPH_H
