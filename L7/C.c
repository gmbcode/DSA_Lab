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
    return q;
}

int peek(Queue* q){
    if(q -> rear == NULL){
        return -1; // Queue is empty
    }
    return q -> front -> data;
}

void enQueue(Queue* q,int data){
    Node* n = createNode(data);
    if(q -> rear == NULL){
        q -> rear = n;
        q -> front = n;
    }
    else{
       q -> rear -> next = n;
       q -> rear = n;
    }
}

int deQueue(Queue* q){
    if(q -> rear == NULL){
        return -1; // Queue is empty
    }
    Node* tmp = q -> front;
    int data = tmp -> data;
    q -> front = tmp -> next;
    if(q -> front == NULL){
        q -> rear = NULL; 
    }
    free(tmp);
    return data;
}
int isEmpty(Queue* q){
    return q->rear == NULL;
}

int main(){
    int n;
    int stack[10000];
    scanf("%d",&n);
    int r1 = 0;
    int tmp;
    Queue* q = createQueue();
    FL(i,0,n){
        scanf("%d",&tmp);
        enQueue(q,tmp);
    }
    FL(i,0,n/2){
        stack[r1++] = deQueue(q);
    }
    while(r1 != 0){
        enQueue(q,stack[--r1]);
    }
    FL(i,0,n/2) {
        enQueue(q,deQueue(q));
    }
    FL(i,0,n/2) {
        stack[r1++] = deQueue(q);
    }
    FL(i,0,n/2) {
        enQueue(q, stack[--r1]);
        enQueue(q, deQueue(q));
    }
    while (!isEmpty(q)) {
        printf("%d ", deQueue(q));
    }
    printf("\n");
    free(q);
}
