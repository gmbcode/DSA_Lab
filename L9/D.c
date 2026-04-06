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

int height(Node* node) {
    if (node == NULL) return 0;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    if (leftHeight > rightHeight) return leftHeight + 1;
    else return rightHeight + 1;
}


void printCurrentLevel(Node* root, int level, int leftToRight) {
    if(root == NULL){
        return;
    }
    if(level == 1){
        printf("%d ", root->data);
    } 
    else if(level > 1){
        if(leftToRight){
            printCurrentLevel(root->left, level - 1, leftToRight);
            printCurrentLevel(root->right, level - 1, leftToRight);
        }
        else{
            printCurrentLevel(root->right, level - 1, leftToRight);
            printCurrentLevel(root->left, level - 1, leftToRight);
        }
    }
}


void printZZ(Node* root) {
    int h = height(root);
    int leftToRight = 1; // Start left-to-right
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i, leftToRight);
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int tmp;
    scanf("%d",&tmp);
    Node* head = createNode(tmp);
    FL(i,1,n){
        scanf("%d", &tmp);
        head = insertNode(head, tmp);
    }
    printZZ(head);
}