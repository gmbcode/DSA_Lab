#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int checkX(int n,int a[],int h,int x);
int main(){
    int n,h;
    scanf("%d %d",&n,&h);
    int a[n];
    int maxS = 0;
    FL(i,0,n){
        scanf("%d",&a[i]);
        maxS = MAX(maxS,a[i]);
    }
    int lo = 1;
    int hi = maxS;
    int ans = maxS;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(checkX(n,a,h,mid)){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    printf("%d\n",ans);

}
int checkX(int n,int a[],int h,int x){
    int tot = 0;
    FL(i,0,n){
        tot += (a[i] + x - 1)/ x; // Ceiling int div (important)
    }
    return tot <= h ;
}