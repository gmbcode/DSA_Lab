#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct Node{
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct Map{
    Node** arr;
    int occupied;
    int buckets;
} Map;

Map* createMap(int buckets){
    Map* map = (Map*) malloc(sizeof(Map));
    map -> buckets = buckets;
    map -> occupied = 0;
    map -> arr = (Node**) calloc(buckets,sizeof(Node*));
    return map;
}
Node* createPair(int key,int value){
    Node* nn = (Node*) malloc(sizeof(Node));
    nn -> key = key;
    nn -> value = value;
    nn -> next = NULL;
    return nn;
}
void insert_Or_Update_IntoMap(Node* element,Map* mp){
    int idx = element -> key % (mp -> buckets);
    if(mp -> arr[idx] == NULL){
        mp -> arr[idx] = element;
        mp -> occupied++;
        return;
    }
    else{
        Node* curr = mp -> arr[idx];
        Node* prev = NULL;
        while(curr != NULL && curr -> key != element -> key){
            prev = curr;
            curr = curr ->next;
        }
        if(curr == NULL){
            prev -> next = element;
            mp -> occupied++;
        }
        else{
            curr -> value += element -> value;
            free(element);
        }
    }
    
}

void printerSpec(Map* mp){
    FL(i,0,mp -> buckets){
        if(mp -> arr[i] != NULL){
            printf("Index %d: ",i);
            Node* curr = mp -> arr[i];
            while(curr != NULL){
                if(curr -> next != NULL){
                    printf("[%d:%d] ->",curr -> key,curr -> value);
                }
                else{
                    printf("[%d:%d]",curr -> key,curr -> value);
                }
                curr = curr -> next;
            }
        }
        else{
            printf("Index %d: Empty",i);
        }
        printf("\n");
    }
}
int main(){
    int m,q;
    scanf("%d %d",&m,&q);
    Map* mp = createMap(m);
    FL(i,0,q){
        int q_type;
        int prod_id,qty;
        scanf("%d",&q_type);
        switch (q_type)
        {
        case 1:
            scanf("%d %d",&prod_id,&qty);
            insert_Or_Update_IntoMap(createPair(prod_id,qty),mp);
            break;
        case 2:
            printerSpec(mp);
            break;
        }
    }
}