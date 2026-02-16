#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long
#define I_MAX INT_MAX
#define I_MIN INT_MIN

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* down;
} Node;

Node* createNode(int val){
    Node* nn = (Node *)malloc(sizeof(Node));
    nn -> val = val;
    nn -> next = NULL;
    nn -> down = NULL;

    return nn;
}


int main(){
    int n;
    scanf("%d",&n);
    int sp[n][n];

    FL(i,0,n){
        FL(j,0,n){
            scanf("%d",&sp[i][j]);
        }
    }
    Node* head = NULL;
    Node* headp = NULL;
    FL(i,0,n){
        Node * tmp = createNode(i);
        if(i == 0){
            head = tmp;
            headp = tmp;
        }
        Node * tmp_p = tmp;
        FL(j,0,n){
            if(sp[i][j]){
                tmp_p -> next = createNode(j);
                tmp_p = tmp_p -> next;
            }
        }
        if(i != 0){
            headp -> down= tmp;
            headp = headp -> down;
        }
    }

    headp = head;
    Node* tmpP = headp;
    while(tmpP != NULL){
        
        Node* tmpH = tmpP;
        while(tmpH != NULL){
            if(tmpH -> next != NULL){
                printf("%d -> ",tmpH -> val);
            }
            else{
                printf("%d\n",tmpH -> val);
            }
            tmpH = tmpH -> next;
        }
        if(tmpP -> down != NULL){
            printf("|\n");
        }
        tmpP = tmpP -> down;
    }
}