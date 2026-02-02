#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int countLE(ll a[], int C,ll val) {
    int low = 0;
    int high = C - 1;
    int count = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= val) {
            count = mid + 1; // 0 based indexing
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return count;
}
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    ll a[r][c];
    ll max = 0;
    ll min = 10000000;
    FL(i,0,r){
        FL(j,0,c){
            scanf("%lld",&a[i][j]);
            max = MAX(max,a[i][j]);
            min = MIN(min,a[i][j]);
        }
    }

    ll lo = min;
    ll hi = max;
    ll count = 0;
    ll ans = 0;
    ll count_req = (r*c) / 2 + 1;
    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        count = 0;
        FL(i,0,r){
            count += countLE(a[i],c,mid);
        }
        if(count >= count_req){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    printf("%lld\n",ans);
}