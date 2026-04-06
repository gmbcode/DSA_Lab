#include <stdlib.h>
#include <stdio.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* head = (Node*) malloc(sizeof(Node));
    head -> data = data;
    head -> left = NULL;
    head -> right = NULL;
    return head;
}

Node* insertNode(Node* head, int data){
    if(head == NULL){
        return createNode(data);
    }
    if(head -> data > data){
        head -> left = insertNode(head -> left, data);
    }
    else if(head -> data < data){
        head -> right = insertNode(head -> right, data);
    }
    return head;
}

Node* getNode(Node* head,int val){
    if(head == NULL){
        return NULL;
    }
    Node* n = head;
    while(n != NULL){
        if(n -> data == val){
            return n;
        }
        else if(n -> data > val){
            n = n -> left;
        }
        else{
            n = n -> right;
        }
    }
    return NULL;
}

int getChildren(Node* n){
    if(n == NULL){
        return 0;
    }
    return 1 + getChildren(n -> left) + getChildren(n -> right);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    Node* head = createNode(a[0]);
    FL(i,1,n){
        insertNode(head,a[i]);
    }
    FL(i,0,n){
        printf("%d ",getChildren(getNode(head,a[i]))-1);
    }
    printf("\n");
}