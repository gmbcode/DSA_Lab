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

    int suc = -1;
    Node* cur = head;
    while(cur != NULL){
        if(cur -> data <= x){
            cur = cur -> right;
        }
        else{
            suc = cur -> data;
            cur = cur -> left;
        }
    }
    printf("%d\n",suc);

}