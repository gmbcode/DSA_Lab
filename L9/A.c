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

Node* insertNode(Node* node,int val){
    if(node == NULL){
        return createNode(val);
    }
    if(val < node -> data){
        node -> left = insertNode(node -> left,val);
    }
    else if(val > node -> data){
        node -> right = insertNode(node -> right,val);
    }
    return node;

}

int main(){
    int n,u,v;
    scanf("%d",&n);
    int tmp;
    Node* head = createNode(-1);
    scanf("%d",&tmp);
    head -> data = tmp;
    FL(i,1,n){
        scanf("%d",&tmp);
        insertNode(head,tmp);
    }  
    scanf("%d %d",&u,&v);
    while((head -> data < u && head -> data < v) || (head -> data > v && head -> data > u)){
        if(head -> data < u && head -> data < v){
            head = head -> right;
        }
        else if(head -> data > v && head -> data > u){
            head = head -> left;
        }
        else{
            break;
        }
    }
    printf("%d\n",head -> data);
}
