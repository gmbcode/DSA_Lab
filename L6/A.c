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

    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    
    int stack[n+1];
    int rear = 0;

    FL(i,0,n){
        while(rear > 0 && a[stack[rear - 1]] <= a[i]){
            rear--;
        }
        if(rear == 0){
            printf("%d ",i + 1);
        }
        else{
            printf("%d ",i - stack[rear - 1]);
        }

        stack[rear++] = i;
    }
    printf("\n");
}