// 2 pointer based simple solution
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

void bsort(int n,int a[],int l,int r);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];

    FL(i,0,n){
        scanf("%d",&a[i]);
    }

    int l = 0;
    int r = n - 1;
    int k = 1;
    int par = 0;
    while (l<=r)
    {
        if(!par){
            if(l + k - 1 <= r){
            bsort(n,a,l,l+k-1);
            par = 1;
            l += k;
            k++;
            }
            else{
                bsort(n,a,l,r);
                break;
            }
        }
        else{
            if(r - k + 1 >= l){
            bsort(n,a,r-k+1,r);
            par = 0;
            r -= k;
            k++;
            }
            else{
                bsort(n,a,l,r);
                break;
            }
        }
    }
    FL(i,0,n){
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
void bsort(int n,int a[],int l,int r){
    int tmp = 0;
    if(l == r){
        return;
    }
    FE(i,l,r){
        FE(j,l+1,r-i+l){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

