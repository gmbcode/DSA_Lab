#include<stdlib.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertNodeatEnd(struct Node* head,int data);
void printList(struct Node* head);

int main(){
    int n;
    scanf("%d",&n);
    int num;
    scanf("%d",&num);
    struct Node* head = createNode(num);
    
    FL(i,1,n){
        scanf("%d",&num);
        insertNodeatEnd(head,num);
    }
    int x;
    scanf("%d",&x);

    FL(i,0,n){
    struct Node* prev = NULL;
    struct Node* temp;
    struct Node* temp1;
    
    temp = head;
    while(temp != NULL && temp-> next != NULL){
        if(temp -> data == x && temp -> next -> data != x){// If both are X DO NOT SWAP
            temp1 = temp -> next;
            if(temp == head){
                head = temp1;
            }
            temp -> next = temp1 -> next;
            temp1 -> next = temp;
            if(prev != NULL){
                prev -> next = temp1;
            }
        }
        prev = temp;
        temp = temp -> next;
        }
    }
    printList(head);
}

struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> next = NULL;
    temp -> data = data;
    return temp;
}

void insertNodeatEnd(struct Node* head,int data){
    struct Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = createNode(data);
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp -> next != NULL){
            printf("%d -> ",temp->data);
        }
        else{
            printf("%d\n",temp->data);
        }
        temp = temp -> next;
    }
}