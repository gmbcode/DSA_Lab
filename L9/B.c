#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* tree = (Node*)malloc(sizeof(Node));
    tree -> left = NULL;
    tree -> right = NULL;
    tree -> data = data;
    return tree;
}

Node* insertNode(Node* head,int data){
    if(head == NULL){
        return createNode(data);
    }
    else if(head -> data < data){
        head -> right = insertNode(head -> right,data);
    }
    else if(head -> data > data){
        head -> left = insertNode(head -> left,data);
    }
    return head;
}

int main(){
    int n,x;
    scanf("%d",&n);
    int tmp;
    scanf("%d",&tmp);
    Node* head = createNode(tmp);
    FL(i,1,n){
        scanf("%d",&tmp);
        insertNode(head,tmp);
    }
    scanf("%d",&x);
    int key = -1;
    while(head != NULL){
        if(head -> data <= x){
            key = head -> data;
            head = head -> right;
        }
        else{
            head = head -> left;
        }
    }
    printf("%d\n",key);
}