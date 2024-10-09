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

void DLSUtil(int vertex, bool visited[], int depth, int limit) {
    // If the depth limit is reached, return
    if (depth > limit) {
        return;
    }

    // Mark the current node as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph[vertex];
    while (temp != NULL) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DLSUtil(adjacentVertex, visited, depth + 1, limit);
        }
        temp = temp->next;
    }
}

void DLS(int startVertex, int vertices, int limit) {
    bool visited[MAX_VERTICES] = { false };
    printf("Depth-Limited Search traversal from vertex %d with limit %d: \n", startVertex, limit);
    DLSUtil(startVertex, visited, 0, limit);
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

    int startVertex, limit;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    printf("Enter the depth limit: ");
    scanf("%d", &limit);

    DLS(startVertex, vertices, limit);
    printf("\n");

    return 0;
}
