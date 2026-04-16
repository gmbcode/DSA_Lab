#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int dp[n][n];
    FL(i,0,n){
        FL(j,0,n){
            dp[i][j] = 0;
        }
    }
    // Let dp[i][j] denote the maximum score someone can get from taking subarray i..j
    FL(i,0,n){
        dp[i][i] = a[i];
    }

    FL(i,0,n-1){
        dp[i][i+1] = MAX(a[i],a[i+1]);
    }

    for(int len = 3 ; len <= n;len++){
        for(int i = 0 ; i <= n - len ; i++){
            int j = i + len - 1;

            int t_left = a[i] + MIN(dp[i+2][j],dp[i+1][j-1]);
            // Max value if we take left and opponent plays optimally giving us min
            int t_right = a[j] + MIN(dp[i+1][j-1],dp[i][j-2]);
            // Max value if we take right and opponent plays optimally giving us min
            dp[i][j] = MAX(t_left,t_right);
        }
    }
    printf("%d\n",dp[0][n-1]);

}