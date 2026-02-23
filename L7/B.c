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
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q -> front = NULL;
    q -> rear = NULL;
    return q;
}

int isEmpty(Queue* q){
    return q->front == NULL;
}
int peek(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    return q->front->data;
}
void enQueue(Queue* q,int data){
    Node* n = createNode(data);
    if(q -> rear == NULL){
        q -> front = n;
        q -> rear = n;
        return;
    }
    q -> rear -> next = n;
    q -> rear = n;
}
int deQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty cannot dequeue\n");
        return -1;
    }
    Node* tmp = q -> front;
    q -> front = q -> front -> next;
    if(q -> front == NULL){
        q -> rear = NULL;
    }
    int data = tmp -> data;
    free(tmp);
    return data;
}
int main(){
    char str[10000];
    int freq[26] = {0};
    Queue* q = createQueue();
    scanf("%s",str);
    int sz = strlen(str);
    FL(i,0,sz){
        enQueue(q,str[i]);
        freq[str[i] - 'a']++;
        while(!isEmpty(q)){
            char cur = peek(q);
            if(freq[cur - 'a'] == 1){
                printf("%c ",cur);
                break;
            }
            else{
                deQueue(q);
            }
        }
        if(isEmpty(q)){
            printf("-1 ");
        }
    }
}