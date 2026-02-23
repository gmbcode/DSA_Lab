#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

typedef struct Node{
    struct Node* next;
    int data;
} Node;

typedef struct Queue{
    struct Node* front;
    struct Node* rear;
    int size;
} Queue;

Node* createNode(int data){
    Node* n = (Node *) malloc(sizeof(Node));
    n -> data = data;
    n -> next = NULL;
    return n;
}

Queue* createQueue(){
    Queue* q = (Queue *) malloc(sizeof(Queue));
    q -> front = NULL;
    q -> rear = NULL;
    q -> size = 0;
    return q;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int peek(Queue* q){
    if(q->size == 0){
        printf("Queue is empty cannot peek\n");
    }
    return q -> front -> data;
}

void enQueue(Queue* q,int data){
    Node* n = createNode(data);
    if(q -> size == 0){
        q -> front = n;
        q -> rear = n;
    }
    else{
        q -> rear -> next = n;
        q -> rear = n;
    }
    q -> size = q -> size + 1;
}

int deQueue(Queue* q){
    if(q -> size == 0){
        printf("Queue is empty cannot deque\n");
        return -1;
    }
    Node* tmp = q -> front;
    int data = tmp -> data;
    q -> front = tmp -> next;
    free(tmp);
    q -> size = q -> size - 1;
    return data;
}

int main(){
    int n;
    scanf("%d",&n);
    int gas[n];
    int dist[n];

    FL(i,0,n){
        scanf("%d",&gas[i]);
    }
    FL(i,0,n){
        scanf("%d",&dist[i]);
    }
    Queue* q = createQueue();
    int curr_gas = 0;
    FL(i,0,2*n){
        int cur = i % n;
        enQueue(q,cur);
        curr_gas += (gas[cur] - dist[cur]);
        while ((curr_gas < 0) && !isEmpty(q)){
            int removed = deQueue(q);
            curr_gas -= (gas[removed] - dist[removed]);
        }
        if(q -> size == n){
            printf("%d\n",peek(q));
            free(q);
            return 0;
        } 
    }
    printf("-1\n");
    free(q);
}