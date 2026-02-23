#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

typedef struct Node {
    struct Node* next;
    int r;
    int c;
    int dist;
} Node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

Node* createNode(int r, int c, int dist) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->r = r;
    n->c = c;
    n->dist = dist;
    n->next = NULL;
    return n;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enQueue(Queue* q, int r, int c, int dist) {
    Node* n = createNode(r, c, dist);
    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
}

Node deQueue(Queue* q) {
    Node tmpData;
    tmpData.r = -1;
    
    if (q->front == NULL) return tmpData;
    
    Node* tmp = q->front;
    tmpData.r = tmp->r;
    tmpData.c = tmp->c;
    tmpData.dist = tmp->dist;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    } 
    free(tmp);
    return tmpData;
}

int iib(int r, int c, int m, int n) {
    return (r >= 0 && r < m && c >= 0 && c < n);
}

int main() {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    Queue* q = createQueue();
    int m, n;
    scanf("%d %d",&m,&n);
    int a[m][n]; 
    int visited[m][n]; 
    
    FL(i, 0, m) {
        FL(j, 0, n) {
            scanf("%d", &a[i][j]);
            visited[i][j] = 0;
        }
    }
    
    enQueue(q, 0, 0, 1);
    visited[0][0] = 1;
    
    while (!isEmpty(q)) {
        Node curr = deQueue(q);
        if (a[curr.r][curr.c] == 2) {
            printf("%d\n", curr.dist);
            return 0; 
        }
        FL(i, 0, 4) {
            int new_r = curr.r + directions[i][0];
            int new_c = curr.c + directions[i][1];
            if (iib(new_r, new_c, m, n) && a[new_r][new_c] != 1 && !visited[new_r][new_c]){
                visited[new_r][new_c] = 1; 
                enQueue(q, new_r, new_c, curr.dist + 1); // Queue it up with +1 distance
            }
        }
    }

    printf("-1\n");
    return 0;
}