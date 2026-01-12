#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

int main(){
    int m,n;
    scanf("%d",&m);
    int arr[m];
    FL(i,0,m){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&n);
    int arr1[n];
    FL(i,0,n){
        scanf("%d",&arr1[i]);
    }
    //int sorted[m+n];
    int index = 0;
    int mx = n;
    int mn = m;
    if(m > n){
        mx = m;
        mn = n;
    }
    int p1 = 0;
    int p2 = 0; // Using 2 pointer method
    while (p1 < mx && p2 < mx)
    {
        if(p1 < mn && p2 < mn){
            if(arr[p1]>arr1[p2]){
                printf("%d ",arr1[p2]);
                p2++;
            }
            else{
                printf("%d ",arr[p1]);
                p1++;
            }
        }
        else{
            if(mn == n){
                printf("%d ",arr[p1]);
                p1++;
            }
            else{
                printf("%d ",arr1[p2]);
                p2++;
            }
        }

    }
    printf("\n");
    
}