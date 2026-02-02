#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int main(){
    ll k;
    scanf("%lld",&k);
    ll lo = 1;
    ll hi = k;
    ll mid;
    ll ans;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(mid*mid <= k){
            lo = mid + 1;
            ans = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    printf("%lld\n",ans);
}