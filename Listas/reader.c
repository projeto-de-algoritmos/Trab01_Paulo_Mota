#include "reader.h"
#include <stdlib.h>

Graph* load_graph(char *nodes_filename, char *edges_filename){
    FILE *file_ptr0 = fopen(nodes_filename, "r");
    
    if(file_ptr0 == NULL) {
        return NULL;
    }

    FILE *file_ptr1 = fopen(edges_filename, "r");
    
    if(file_ptr1 == NULL) {
        return NULL;
    }

    Graph *grafo = create_graph(nodes_filename);
    int id, src, dst;
    char name[50];
    NodeData insert_node;

    while(!feof(file_ptr0)) {
        fscanf(file_ptr0, "%d\t%s\n", &id, name);
        strcpy(insert_node.name, name);
        add_node(grafo, id);
        set_node_value(grafo, id, insert_node);
    }

    while(!feof(file_ptr1)) {
        fscanf(file_ptr1, "%d\t%d\n", &src, &dst);
        add_edge(grafo, src, dst);
        add_edge(grafo, dst, src);
    }
    
    fclose(file_ptr0);
    fclose(file_ptr1);

    return grafo;
}
