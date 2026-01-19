#include<stdlib.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

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
    int k;
    scanf("%d",&k);
    k = k % n;
    //printList(head);
    if(k == 0){
        printList(head);
    }
    struct Node* last = head;
    struct Node* temp = head;
    while(last-> next != NULL){
        last = last -> next;
    }//Get last node of the linked list
    last -> next = head;// Make linked list circular for now
    int steps = n - k - 1; // Important
    FL(i,0,steps){
        temp = temp -> next;
    }
    head = temp -> next;
    temp -> next = NULL; // Break the circular Linked list at the correct point
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
        if(temp -> next == head){
            printf("Circular linked list detected\n");
            return;
        }
        temp = temp -> next;
    }
    temp -> next = createNode(data);
}
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp -> next == head){
            printf("Circular linked list detected\n");
            return;
        }
        if(temp -> next != NULL){
            printf("%d -> ",temp->data);
        }
        else{
            printf("%d\n",temp->data);
        }
        temp = temp -> next;
    }
}