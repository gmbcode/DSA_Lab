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

int getSum(Node* head){
    if(head == NULL){
        return 0;
    }
    return head -> data + getSum(head -> left) + getSum(head -> right);
}
int main(){
    int n,x;
    scanf("%d",&n);
    int tmp;
    scanf("%d", &tmp);
    Node* head = createNode(tmp);
    FL(i,1,n){
        scanf("%d", &tmp);
        head = insertNode(head, tmp);
    }
    scanf("%d",&x);
    Node* node = getNode(head,x);
    printf("%d\n",getSum(node));
}