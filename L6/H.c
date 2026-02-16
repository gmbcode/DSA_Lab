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

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    FL(i,0,n){ 
        scanf("%d",&b[i]);
    }
    int stack[n+100];
    int op_f[2*n]; // 2 is important
    int rear = 0;
    int index = 0;
    int opc = 0;
    FL(i,0,n){
        stack[rear++] = a[i];
        op_f[opc++] = 1;
        while(rear > 0 && stack[rear-1] == b[index]){
            op_f[opc++] = 0;
            index++;
            rear--;
        }
    }

    if(index == n){
        FL(i,0,opc){
            if(op_f[i]){
                printf("Push\n");
            }
            else{
                printf("Pop\n");
            }
        }
    }
    else{
        printf("Impossible\n");
    }
}