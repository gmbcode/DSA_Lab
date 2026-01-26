#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ll long long

ll f(ll y);

int main(){
    ll y;
    scanf("%lld",&y);
    ll lo = 0;
    ll hi = 80;
    ll mid;
    ll ans = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(f(mid) <= y){
            ans = mid;
            if(f(mid) == y){
                break;
            }
            lo = mid + 1;
        }
        else if(f(mid) > y){
            hi = mid - 1;
        }
    }
    printf("%lld\n",ans);
}

ll f(ll x){
    return 2*(x*x*x) - (x*x) + 5*x ;
}