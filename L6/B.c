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
    int ans[n];
    int rear = 0;

    for(int i = n - 1 ; i >= 0 ; i--){
        while(rear > 0 && a[stack[rear - 1]] <= a[i]){
            rear--; // We find day warmer than a[i]
        }
        if(rear == 0){
            ans[i] = 0;
        }
        else{
            ans[i] = abs(stack[rear - 1] - i); 
        }
        stack[rear++] = i;
    }

    FL(i,0,n){
        printf("%d ",ans[i]);
    }
    printf("\n");
}