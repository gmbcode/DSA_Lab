#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

struct Node {
    int data;
    struct Node* next;
};
void insertNodeatEnd(struct Node* head,int data);
void printList(struct Node* head);
struct Node* createNode(int data);
int main(){
    int n;
    scanf("%d",&n);
    int temp;
    scanf("%d",&temp);
    struct Node* head = createNode(temp);
    FL(i,1,n){
        scanf("%d",&temp);
        insertNodeatEnd(head,temp);
    }
    //printList(head);
    struct Node* tempc = head;
    struct Node* slow = tempc;
    struct Node* fast = tempc;
    while(fast != NULL){
        slow = slow->next;
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
    }
    // Now slow is midpoint we reverse the second half
    struct Node* prev = NULL;
    struct Node* cur = slow;
    struct Node* next;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    } // We reverse the second half of LL
    int flag = 1; // It is palindromic
    //printList(tempc);
    //printList(prev);
    while(prev != NULL){
        if(tempc -> data != prev -> data){
            flag = 0;
            break;
        }
        tempc = tempc -> next;
        prev = prev -> next;
    }
    if(flag){
        printf("True\n");
    }
    else{
        printf("False\n");
    }

}

struct Node* createNode(int data){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    if(head == NULL){
        printf("Memory allocation failed");
    }
    head -> data = data;
    head -> next = NULL;
    return head;
}
void insertNodeatEnd(struct Node* head,int data){
    struct Node* temp = head;
    while(temp -> next != NULL){
        if(temp -> next == head){
            //We have identified a circular linked list
            printf("Circular linked lists not supported");
            return;
        }
        temp = temp->next;
    }
    struct Node* new_node = createNode(data);
    temp -> next = new_node;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp -> next == head){
            //We have identified a circular linked list
            printf("Circular linked lists not supported");
            return;
        }
        if(temp -> next != NULL){
            printf("%d -> ",temp -> data);
        }
        else{
            printf("%d\n",temp -> data);
        }
        temp = temp->next;
    }
}