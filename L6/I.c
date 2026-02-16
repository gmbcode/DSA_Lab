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
    ll a[n+1];
    FL(i,0,n){
        scanf("%lld",&a[i]);
    }
    a[n] = 0;
    ll stack[n+1];
    int rear = 0;
    ll sm = 0;
    FE(i,0,n){
        while(rear != 0 && a[stack[rear - 1]] > a[i]){
            ll top = stack[--rear];
            ll current = a[top];
            ll right = i - top;
            ll left;
            if(rear == 0){
                left = top + 1;
            }
            else{
                left = top - stack[rear - 1];
            }
            sm += current*left*right;
        }
        stack[rear++] = i;
    }
    printf("%lld",sm); 
}