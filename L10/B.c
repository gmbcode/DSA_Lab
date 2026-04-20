#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct Node{
    int id;
    struct Node* next;
} Node;


Node* createNode(int val){
    Node* nn = (Node*) malloc(sizeof(Node));
    nn -> id = val;
    nn -> next = NULL;
    return nn;
}
void insertFunction(Node** table, int id, int m){
    int idx = id % m;
    
    while(1) {
        if(table[idx] == NULL){ 
            table[idx] = createNode(id);
            return;
        }
        

        if(table[idx]->id < 1000 && id >= 1000){ 
            int kicked_out_id = table[idx]->id;
            table[idx]->id = id; 
            id = kicked_out_id;  
        }
        
        idx = (idx + 1) % m;
    }
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    Node** table =(Node**) calloc(m,sizeof(Node*));
    int tmp;
    FL(i,0,n){
        scanf("%d",&tmp);
        insertFunction(table,tmp,m);
    }
    FL(i,0,m){
        if(table[i] != NULL){
            printf("%d ",table[i] -> id);
        }
        else{
            printf("-1 ");
        }
    }
    printf("\n");
}