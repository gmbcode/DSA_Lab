#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int val){
    Node* nn = (Node*) malloc(sizeof(Node));
    nn->val = val;
    nn->next = NULL;
    return nn;
}

void insertOrdered(Node** table,int val,int m){
    int idx = val % m;
    Node* nn = createNode(val);

    // If table is empty or element is smaller than head
    if(table[idx] == NULL || table[idx]->val > val){
        nn -> next = table[idx];
        table[idx] = nn;
        return;
    }

    Node* curr = table[idx];
    // find point to insert
    while(curr -> next != NULL && curr -> next -> val < val){
        curr = curr -> next;
    }
    nn -> next = curr -> next;
    curr -> next = nn;
}

int searchSorted(Node** table,int val,int m){
    int idx = val % m;
    Node* curr = table[idx];
    while(curr != NULL){
        if(curr -> val == val) return 1;
        if(curr -> val > val) break;
        curr = curr -> next;
    }
    return 0;
}


int main(){
    int m, nA, nB;
    int tmp;
    scanf("%d %d %d", &m, &nA, &nB);
    Node** table = (Node**)calloc(m, sizeof(Node*));
    FL(i,0,nA){
        scanf("%d",&tmp);
        insertOrdered(table,tmp,m);
    }

    int found_any = 0;
    FL(i,0,nB){
        scanf("%d",&tmp);
        if(searchSorted(table,tmp,m)){
            if(!found_any){
                printf("Intersection:");
                found_any = 1;
            }
            printf(" %d",tmp);
        }
    }
    if(!found_any){
        printf("Intersection: None\n");
    } 
    else{
        printf("\n");
    }
}

