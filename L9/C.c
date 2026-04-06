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
int getCount(Node* head,int l,int r){
    if(head == NULL){
        return 0;
    }
    if (head->data >= l && head->data <= r) {
        return 1 + getCount(head->left, l, r) + getCount(head->right, l, r);
    }
    if (head->data < l) {
        return getCount(head->right, l, r);
    }
    if (head->data > r) {
        return getCount(head->left, l, r);
    }
}
int main(){
    int n,l,r;
    scanf("%d",&n);
    int tmp;
    scanf("%d",&tmp);
    Node* head = createNode(tmp);
    FL(i,1,n){
        scanf("%d",&tmp);
        insertNode(head,tmp);
    }
    scanf("%d %d",&l,&r);
    printf("%d\n",getCount(head,l,r));
}