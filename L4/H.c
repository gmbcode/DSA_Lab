#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int isPossible(int a[], int n, int k, int time_limit);

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    int mx = 0;
    int sm = 0;
    FL(i,0,n){
        scanf("%d",&a[i]);
        sm += a[i];
        mx = MAX(mx,a[i]);
    }

    int lo = mx;
    int hi = sm;
    int mid;
    int ans;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if(isPossible(a,n,k,mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }

    }
    printf("%d\n",ans);
    return 0;
}

int isPossible(int a[], int n, int k, int time_limit){
    int ptr_used = 1;
    int current_time = 0;
    FL(i,0,n){
        if(current_time + a[i] <= time_limit){
            current_time += a[i];
        }
        else{
            ptr_used++;
            current_time = a[i];
            if(ptr_used > k){
                return 0;
            }
        }
    }
    return 1;
}