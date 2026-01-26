#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(){
    int n,target;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    scanf("%d",&target);
    int ans = -1;
    int lo = 0;
    int hi = n - 1;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(a[mid] == target){
            ans = target;
            break;
        }
        else if(a[mid] > target){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    if(ans == -1){
        printf("-1 -1\n");
        return 0;
    }
    int indexL = mid;
    int indexR = mid;
    while(indexL >= 0 && a[indexL] == target){
        indexL--;
    }
    indexL++;
    while(indexR < n && a[indexR] == target){
        indexR++;
    }
    if(a[indexL] != target){
        indexL++;
    }
    if(a[indexR] != target){
        indexR--;
    }
    printf("%d %d\n",indexL,indexR);   
}