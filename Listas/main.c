#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "graph.h"
#include "reader.h"

int main() {

    Graph *grafo = load_graph("nodes.txt", "edges.txt");

    menu(grafo);
    
    int id;
    char name[50];
    NodeData insert_node;
    int conection;
    char option;

    do {
        option = catch_option();

        switch (option) {
            case 1:
                printf("Coloque o id da pessoa: ");
                scanf("%d", &id);
                printf("Coloque o nome da pessoa: ");
                scanf("%s", name);
                getchar();
                add_node(grafo, id);
                strcpy(insert_node.name, name);
                set_node_value(grafo, id, insert_node);
                menu(grafo);
            break;

            case 2:
                printf("Digite o id das duas pessoa amigas: ");
                scanf("%d %d", &id, &conection);
                add_edge(grafo, id, conection);
                add_edge(grafo, conection, id);
            break;

            case 3:
                printf("Digite o id da pessoa que deseja retirar: ");
                scanf("%d", &id);
                remove_node(grafo, id);
                menu(grafo);
            break;

            case 4:
                printf("Digite o id das duas pessoas que brigaram: ");
                scanf("%d %d", &id, &conection);
                remove_edge(grafo, id, conection);
                remove_edge(grafo, conection, id);
            break;

            case 5:
                printf("Digite o id que deseja ver sua Lista de Amigos: ");
                scanf("%d", &id);
                invite(grafo, id);
            break;

            case 0:
                printf("Ate a proxima!\n\n");
            break;

            default:
                printf("DIGITE UMA OPCAO VALIDA\n\n");
            break;
        }
    } while (option != 0);

    destroy_graph(grafo);

    return 0;
}