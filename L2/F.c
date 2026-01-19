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

    struct Node* temp = head;
    struct Node* old;
    while(temp != NULL && temp -> next != NULL){
        if(temp -> next -> data <= temp -> data){
            old = temp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
            free(old);
        }
        else{
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