// BFS Traversal of a Graph using Adjacency Matrix

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct queue{  
    int size;
    int front;
    int rear;
    int* arr;
};

// Function to add an element to the queue
void enqueue(struct queue* q, int val){
    if(q->rear == q->size - 1){
        printf("Queue Overflow\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue* q){
    int a = -1;
    if(q->front == q->rear){
        printf("Queue Underflow\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

// BFS function
void BFS(int start, int a[7][7], int Visited[], struct queue* q) {

    printf("%d ", start);
    Visited[start] = 1;
    enqueue(q, start);

    while(!(q->front == q->rear)) { // while queue is not empty
        int node = dequeue(q);

        for(int j = 0; j < 7; j++) {
            if(a[node][j] == 1 && Visited[j] == 0) { // if there is an edge and not visited
                printf("%d ", j);
                Visited[j] = 1;  // mark as visited
                enqueue(q, j);   
            }
        }
    }
}

int main(){

    struct queue q;
    q.size = 400;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size*sizeof(int)); 

    int Visited[7] = {0};

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
    printf("Enter starting node for BFS: ");
    scanf("%d", &start);

    BFS(start, a, Visited, &q); // BFS Traversal

    return 0;
}
