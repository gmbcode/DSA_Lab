#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long



int main(){
    int n,g;
    scanf("%d %d",&n,&g);
    int a[n];
    ll max = 0;
    
    FL(i,0,n){
        scanf("%d",&a[i]);
        max = MAX(max,a[i]);
    }
    ll lo = 1;
    ll hi = max;
    ll mid;
    ll ans = -1;
    ll tot = 0;
    while (lo <= hi){
        tot = 0;
        mid = lo + (hi - lo) / 2;
        FL(i,0,n){
            tot += MIN(a[i],mid);
        }
        if(tot >= g){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    printf("%lld\n",ans);
    
}
