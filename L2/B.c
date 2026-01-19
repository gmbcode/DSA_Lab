#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

struct Node {
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
    struct Node* prev = head;
    struct Node* next = head -> next;
    struct Node* pc = prev;
    struct Node* nx = next;
    if(n == 1){
        printList(head);
    }
    FL(i,0,n){
        FL(j,1,n-i){
            if(pc -> data % 2 != 0 && nx -> data % 2 == 0){
                num = pc -> data;
                pc -> data = nx -> data;
                nx -> data = num;
            }
            pc = pc -> next;
            nx = nx -> next;
        }
        pc = prev;
        nx = next;
    }
    printList(head);
}

struct Node* createNode(int data){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head -> next = NULL;
    head -> data = data;
    return head;
}
void insertNodeatEnd(struct Node* head,int data){
    struct Node* temp = head;
    while(temp->next != NULL){
        if(temp->next == head){
            printf("Circular linked list detected\n");
        }
        temp = temp -> next;
    }
    temp -> next = createNode(data);
}
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->next == head){
            printf("Circular linked list detected\n");
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