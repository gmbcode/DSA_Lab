#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
// The Freelance Developer's Dilemma
int main(){
    int n,h;
    scanf("%d %d",&n,&h);
    int pay[n];
    int hours[n];
    int dp[h+1];
    FL(i,0,n){
        scanf("%d",&pay[i]);
    }
    FL(i,0,n){
        scanf("%d",&hours[i]);
    }
    FL(i,0,h+1){
        dp[i] = 0;
    }
    dp[0] = 0; // Max pay working for 0 hours is 0

    FL(i,0,n){
        for(int j = h; j >= hours[i] ; j--){
            dp[j] = MAX(dp[j],pay[i] + dp[j - hours[i]]);
        }
    }
    printf("%d\n",dp[h]);
}