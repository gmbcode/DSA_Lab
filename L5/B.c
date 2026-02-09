#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int start = 0;
    int end = 1;
    int prev = a[end] - a[start];
    int len = 1;
    int mxl = 0;
    int smax = 0;
    int emax = 0;
    while (start < n && end < n && start <= end)
    {
        if((a[end] - a[end-1]) == prev){
            len++;
            if(len > mxl){
                mxl = len;
                smax = start;
                emax = end;
            }
            end++;
        }
        else{
            if(len > mxl){
                mxl = len;
                smax = start;
                emax = end - 1;
            }
            len = 1;
            start = end - 1;
            prev = a[end] - a[start];
        }
    }
    printf("%d %d",smax+1,emax+1);
    
}