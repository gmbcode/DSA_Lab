#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int mapper(int index,int n,int rotIndex);

int main(){
    int n;
    int target;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    scanf("%d",&target);
    int flag = 0;
    int rotIndex = 0;
    FL(i,1,n){
        if(a[i] < a[i-1]){
            flag = 1;
            rotIndex = i;
            break;
        }
    }
    int lo = 0;
    int hi = n-1;
    int mid;
    int ans = -1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(a[mapper(mid,n,rotIndex)] == target){
            ans = mapper(mid,n,rotIndex);
            break;
        }
        else if(a[mapper(mid,n,rotIndex)] > target){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    printf("%d\n",ans);
    
    
}

int mapper(int index,int n,int rotIndex){
    if(rotIndex){
        return (index + rotIndex)  % n;
    }
    else{
        return index;
    }
}