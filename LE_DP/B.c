#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int main(){
    int n,h;
    int pay[n];
    int hours[n];
    scanf("%d %d",&n,&h);
    FL(i,0,n){
        scanf("%d",&pay[i]);
    }
    FL(i,0,n){
        scanf("%d",&hours[i]);
    }
    // Map to 0-1 knapsack
    int dp[h+1]; // DP [i] stores max payment you can get working for exactly i hours
    FL(i,0,h+1){
        dp[i] = 0;
    }
    FL(i,0,n){
        for(int w = h ; w >= hours[i];w--){
            dp[w] = MAX(dp[w],dp[w - hours[i]] + pay[i]);
        }
    }

    printf("%d\n",dp[h]);

}