#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#define ll long long

typedef struct{
    int x;
    int min
} st;

int main(){
    int n;
    char buf[1024];
    char* cursor = buf;
    scanf("%d",&n);
    st stack[n];
    int rear = 0;
    int top;
    FL(i,0,n){
        int op;
        scanf("%d",&op);
        if(rear == 0 && op != 1){
            cursor += sprintf(cursor,"Stack Empty\n");
            continue;
        }
        if(op == 1){
            int x;
            scanf("%d",&x);
            stack[rear].x = x;
            if(rear == 0){
                stack[rear].min = x;
            }
            else{
                stack[rear].min = MIN(stack[rear-1].min,x);
            }
            rear++;
        }
        else if(op == 2){
            cursor += sprintf(cursor,"Popped: [%d]\n",stack[rear-1].x);
            rear--;
        }
        else if(op == 3){
            cursor += sprintf(cursor,"Minimum: [%d]\n",stack[rear-1].min);
        }
        else if(op == 4){
            cursor += sprintf(cursor,"Top: [%d]\n",stack[rear-1].x);
        }
    }
    printf("%s",buf);
}