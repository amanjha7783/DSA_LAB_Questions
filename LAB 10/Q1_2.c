// DFS Traversal of a Graph using Adjacency Matrix

#include <stdio.h>
#include <stdlib.h>

void DFS(int a[7][7], int visited[], int node){
    printf("%d ",node);
    visited[node] = 1;
    for(int i=0;i<7;i++){
        if(a[node][i] == 1 && visited[i] == 0){ // if there is an edge and not visited
            DFS(a,visited,i);
        }
    }
}

int main(){

    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {            // adjacency matrix
        {0,1,1,1,0,0,0},      // 0 is connected to 1,2,3
        {1,0,1,0,0,0,0},     // 1 is connected to 0,2
        {1,1,0,1,1,0,0},    // 2 is connected to 0,1,3,4
        {1,0,1,0,0,1,1},   // 3 is connected to 0,2,5,6
        {0,0,1,1,0,1,1},  // 4 is connected to 2,3,5,6
        {0,0,0,1,1,0,0}, // 5 is connected to 3,4
        {0,0,0,0,1,0,0},// 6 is connected to 4
    };

    printf("we have 7 nodes in the graph numbered from 0 to 6\n");
    int start;
    printf("Enter the starting node for DFS: ");    
    scanf("%d",&start);

    printf("DFS Traversal: ");
    DFS(a,visited,start);

    return 0;
}