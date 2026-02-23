#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
    Queue* entry = createQueue();
    Queue* arrival = createQueue();

    int time[n];
    int direction[n];
    int ans[n];
    FL(i,0,n){
        scanf("%d",&time[i]);
    }
    FL(i,0,n){
        scanf("%d",&direction[i]);
    }

    FL(i,0,n){
        if(direction[i] == 0){
            enQueue(entry,i);
        }
        else{
            enQueue(arrival,i);
        }
    }

    int curr_time = 0;
    int prev_dir = -1; // -1 for idle
    int t0,t1;
    while((!isEmpty(entry)) || (!isEmpty(arrival))){
        
        if(isEmpty(entry)){
            t0 = INT_MAX;
        }
        else{
            t0 = time[peek(entry)];
        }
        if(isEmpty(arrival)){
            t1 = INT_MAX;
        }
        else{
            t1 = time[peek(arrival)];
        }
        if(curr_time < t0 && curr_time < t1){// If no one has arrived we can skip to the min of t0,t1
            curr_time = MIN(t0,t1);
            prev_dir = -1; // The elevator was just idle
        }
        int wait0 = (t0 <= curr_time);
        int wait1 = (t1 <= curr_time);

        if(wait0 && wait1){
            if(prev_dir == 0){
                ans[deQueue(entry)] = curr_time;
                prev_dir = 0;
            }
            else{
                ans[deQueue(arrival)] = curr_time;
                prev_dir = 1;
            }
        }
        else if(wait0){
            ans[deQueue(entry)] = curr_time;
            prev_dir = 0;
        }
        else if(wait1){
            ans[deQueue(arrival)] = curr_time;
            prev_dir = 1;
        }

        curr_time++;
    }

    FL(i,0,n){
        printf("%d ",ans[i]);
    }
    printf("\n");


}