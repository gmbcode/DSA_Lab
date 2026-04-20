#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long

int m,n;
typedef struct Node{
    int key;
    int frequency;
    struct Node* next;
} Node;

Node* createNode(int key){
    Node* nn = (Node*) malloc(sizeof(Node));
    nn -> key = key;
    nn -> frequency = 1;
    nn -> next = NULL;
    return nn;
}


void insertNode(Node** table,Node* n){
    int idx = n -> key % m;
    Node* prev = NULL;
    Node* curr = table[idx];
    while(curr != NULL && curr -> key != n -> key){
        prev = curr;
        curr = curr -> next;
    }
    if(curr == NULL){
        if (prev == NULL){
            table[idx] = n;
        }
        else{
            prev->next = n; 
        }
    }
    else{
        curr -> frequency++;
        free(n);
    }
}

int main(){
    scanf("%d %d",&m,&n);
    Node** table = (Node**) calloc(m,sizeof(Node*));
    int tmp;
    FL(i,0,n){
        scanf("%d",&tmp);
        insertNode(table,createNode(tmp));
    }
    int mxf = 0;
    int el = INT_MAX;
    FL(i,0,m){
        if(table[i] != NULL){
            Node* curr = table[i];
            printf("Index %d: ",i);
            while(curr != NULL){
                if(curr -> next != NULL)
                printf("[%d:%d] ->",curr -> key,curr -> frequency);
                else
                printf("[%d:%d]\n",curr -> key,curr -> frequency);
                if (curr->frequency > mxf) {
                    // New absolute maximum found
                    mxf = curr->frequency;
                    el = curr->key;
                } 
                else if(curr->frequency == mxf && curr->key < el){
                    // Tie-breaker: same frequency, but smaller key
                    el = curr->key;
                }
                curr = curr -> next;
            }

        }
        else{
            printf("Index %d: Empty\n",i);
        }
    }
    printf("%d %d",el,mxf);

}