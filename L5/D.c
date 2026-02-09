#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int isPossible(int n,int a[],int gap,int k);
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int lo = 1;
    int hi = a[n-1] - a[0];
    int mid;
    int cur_ans = 1;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(isPossible(n,a,mid,k)){
            lo = mid + 1;
            cur_ans = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    
    printf("%d\n",cur_ans);
}

int isPossible(int n,int a[],int gap,int k){
    int numT = 1;
    int curGp = a[1] - a[0];
    int start = 0;
    FL(i,1,n){
        curGp = a[i] - a[start];
        if(curGp >= gap){
            numT++;
            start = i;
        }
    }
    if(numT >= k){
        return 1;
    }
    else{
        return 0;
    }
}