#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MOD 1000000009
// Mars Rover Debris Navigation
int iib(int i,int j,int m,int n){
    if((i>=0 && i < m) && (j>=0 && j < n)){
        return 1;
    }
    return 0;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int grid[m][n];
    int dp[m][n];
    FL(i,0,m){
        FL(j,0,n){
            scanf("%d",&grid[i][j]);
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    FL(i,0,m){
        FL(j,0,n){
            if(i == 0 && j == 0){
                continue;
            }
            if(!grid[i][j]){
                if(iib(i-1,j,m,n)){
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }
                if(iib(i,j-1,m,n)){
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    printf("%d\n",dp[m-1][n-1]);


    
    
}