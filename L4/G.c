#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[n];
    FL(i, 0, n){
        scanf("%d", &a[i]);
    }
    
    int lo = 0;
    int hi = n - 1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        
        int missing = a[mid] - (mid + 1);
        if(missing < k){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    

    printf("%d\n", lo + k);
    
    return 0;
}