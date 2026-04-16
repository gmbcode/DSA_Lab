#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char s1[n+1];
    char s2[m+1];
    scanf("%s",s1);
    scanf("%s",s2);
    int dp[n+1][m+1];
    FL(i,0,n+1){
        FL(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    FL(i,0,n+1){
        dp[i][0] = 1;
    }
    FL(j,1,m+1){
        dp[0][j] = 0;
    }
    FL(i,1,n+1){
        FL(j,1,m+1){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d\n",dp[n][m]);
    

}