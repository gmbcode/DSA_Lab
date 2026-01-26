#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void bubblesort(int n,int a[],int l,int r);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int l = 0;
    int r = 0;
    int mult = 2;
    while(1){
        bubblesort(n,a,l,r);
        l = r+1;
        r += mult;
        mult++;
        if(l > n-1){
            break;
        }
        if(r > n-1){
            r = n-1;
        }
    }
    FL(i,0,n){
        printf("%d ",a[i]);
    }
    printf("\n");

}

void bubblesort(int n,int a[],int l,int r){
    int temp;
    if(r == l){
        return;
    }
    FL(i,l,r+1){
        FL(j,l+1,r+1){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}