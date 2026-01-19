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

    //printList(head);

    struct Node* temp = head;
    struct Node* newHead = NULL; 
    struct Node* prev = NULL; 

    if(head != NULL && head->next != NULL){
        newHead = head->next; 
    } else {
        newHead = head; 
    }

    while(temp != NULL && temp->next != NULL){
        struct Node* n1 = temp;
        struct Node* n2 = temp->next;
        struct Node* nextPair = n2->next; 
        n2->next = n1;
        n1->next = nextPair;

        if(prev != NULL){
            prev->next = n2;
        }

        prev = n1;
        temp = nextPair; 
    }
    
    head = newHead; 
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