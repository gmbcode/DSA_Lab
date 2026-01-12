#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

void leftShift(int a[],int n){
    int temp = a[0];
    FL(i,1,n){
        a[i-1] = a[i];
    }
    a[n-1] = temp;
}
void rightShift(int a[],int n){
    int temp = a[n-1];
    for(int i = n - 1 ; i > 0 ; i--){
        a[i] = a[i-1];
    }
    a[0] = temp;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int d;
    int k;
    scanf("%d",&d);
    scanf("%d",&k);
    k = k % n ; // Offset to remove unnecessary computation
    if(d){
        FL(i,0,k){
            rightShift(a,n);
        }
    }
    else{
        FL(i,0,k){
            leftShift(a,n);
        }
    }
    FL(i,0,n){
        printf("%d ",a[i]);
    }
    printf("\n");

}