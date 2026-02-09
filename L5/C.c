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
    
    int l = a[0];
    int r = a[2];
    FL(i,3,n){
        r ^= a[i];
    }
    if(l == r){
        printf("%d ",2);
    }
    FL(i,1,n-2){
        l ^= a[i];
        r ^= a[i+1];
        if(l == r){
            printf("%d ",i+2);
        }
    }
    printf("\n");
    
}