#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX_VERTICES];

void addEdge(int from, int to) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = to;
    newNode->next = graph[from];
    graph[from] = newNode;
}

void DFSUtil(int vertex, bool visited[]) {
    // Mark the current node as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph[vertex];
    while (temp != NULL) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFSUtil(adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(int startVertex, int vertices) {
    bool visited[MAX_VERTICES] = { false };
    printf("DFS traversal from vertex %d: \n", startVertex);
    DFSUtil(startVertex, visited);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        graph[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (from to): \n");
    for (int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(from, to);
        // Uncomment the next line for an undirected graph
        // addEdge(to, from); 
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    DFS(startVertex, vertices);
    printf("\n");

    return 0;
}
