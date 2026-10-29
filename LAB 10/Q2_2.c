// Kruskal's Algorithm in C

#include <stdio.h>

#define V 5      // number of vertices
#define E 7      // number of edges
#define INF 9999

// Structure for storing edges
struct Edge {
    int u, v, w;
};

// Find parent
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of sets 
void unionSet(int parent[], int x, int y) {
    parent[y] = x;
}

// Kruskal's function
void kruskal(struct Edge edges[]) {
    int parent[V], count = 0;
    struct Edge result[V];

    // Initialize parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight (bubble sort)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Minimum Spanning Tree using Kruskal:\n");

    // Main Kruskal loop
    for (int i = 0; i < E && count < V - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        // If no cycle
        if (set_u != set_v) {
            result[count++] = edges[i];
            unionSet(parent, set_u, set_v);
        }
    }

    // Print MST
    for (int i = 0; i < count; i++) {
        printf("Edge %d - %d   Cost: %d\n",
               result[i].u, result[i].v, result[i].w);
    }
}

int main() {

    struct Edge edges[E] = {        // edge list
        {0, 1, 2},      // edge from node 0 to 1 with weight 2 
        {1, 2, 3},       // edge from node 1 to 2 with weight 3
        {0, 3, 6},     // edge from node 0 to 3 with weight 6
        {1, 3, 8},       // edge from node 1 to 3 with weight 8
        {1, 4, 5},     // edge from node 1 to 4 with weight 5       
        {2, 4, 7},     // edge from node 2 to 4 with weight 7           
        {3, 4, 9}   // edge from node 3 to 4 with weight 9                      
    };

    kruskal(edges); // calling function

    return 0;
}
