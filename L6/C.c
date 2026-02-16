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
    int rear = 0;
    ll max_area = 0;
    int stack[n+1];

    FE(i,0,n){
        int current_height = (i == n) ? 0 : a[i];
        while (rear > 0 && a[stack[rear - 1]] > current_height) {
            int h = a[stack[--rear]]; 
            int width;
            if (rear == 0) {
                width = i; 
            } else {
                width = i - stack[rear - 1] - 1;
            }

            ll area = (long long)h * width;
            max_area = MAX(max_area, area);
        }
        stack[rear++] = i;
    }
    printf("%d\n",max_area);
}