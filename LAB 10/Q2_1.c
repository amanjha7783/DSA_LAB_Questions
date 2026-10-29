//  Prim's Algorithm for Minimum Spanning Tree

#include <stdio.h>

#define INF 9999
#define V 5   // number of vertices

// Function to implement Prim's Algorithm
void prims(int graph[V][V]) {
    int visited[V] = {0};
    int edges = 0;
    int min, a, b;

    visited[0] = 1; // start from node 0

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");

    while (edges < V - 1) {
        min = INF;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("Edge %d - %d  Cost: %d\n", a, b, min);
        visited[b] = 1;
        edges++;
    }
}

int main() {

    int graph[V][V] = {    // adjacency matrix representation
        {0, 2, 0, 6, 0},  // 0 is connected to 1 and 3 with weights 2 and 6
        {2, 0, 3, 8, 5},  // 1 is connected to 0, 2, 3, and 4 with weights 2, 3, 8, and 5
        {0, 3, 0, 0, 7}, // 2 is connected to 1 and 4 with weights 3 and 7
        {6, 8, 0, 0, 9},  // 3 is connected to 0, 1, and 4 with weights 6, 8, and 9
        {0, 5, 7, 9, 0}  // 4 is connected to 1, 2, and 3 with weights 5, 7, and 9
    };

    prims(graph); // calling Prim's function
    
    return 0;
}
