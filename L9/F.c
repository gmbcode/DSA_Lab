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
    int n,a,b;
    scanf("%d",&n);
    int tmp;
    scanf("%d", &tmp);
    Node* head = createNode(tmp);
    FL(i,1,n){
        scanf("%d", &tmp);
        head = insertNode(head, tmp);
    }
    scanf("%d %d",&a,&b);
    Node* t = head;
    int s1 = 0;
    int s2 = 0;
    while(t != NULL && ((t -> data < a && t -> data < b) || (t -> data > a && t -> data > b))){
        if(t -> data < a && t -> data < b){
            t = t -> right;
        }
        else if(t -> data > a && t -> data > b){
            t = t -> left;
        }
    }// Now t should be at LCA
    Node* p1 = t;
    while(p1 -> data != a){
        if(p1 -> data > a){
            p1 = p1 -> left;
            s1 += p1 -> data;
        }
        else if(p1 -> data < a){
            p1 = p1 -> right;
            s1 += p1 -> data;
        }
    }
    p1 = t;
    while(p1 -> data != b){
        if(p1 -> data > b){
            p1 = p1 -> left;
            s2 += p1 -> data;
        }
        else if(p1 -> data < b){
            p1 = p1 -> right;
            s2 += p1 -> data;
        }
    }
    int tot = s1 + s2 + t -> data;
    printf("%d\n",tot);
}