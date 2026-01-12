#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = new Graph;
    graph->numVertices = vertices;
    graph->adjLists = new Node*[vertices];
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, vertices, src, dest;
    struct Graph* graph = NULL;

    while (1) {
        printf("\n1. Create graph");
        printf("\n2. Add edge");
        printf("\n3. Print graph");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                break;
            case 2:
                if (graph == NULL) {
                    printf("Create a graph first!\n");
                    break;
                }
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 3:
                if (graph == NULL) {
                    printf("Create a graph first!\n");
                    break;
                }
                printGraph(graph);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
