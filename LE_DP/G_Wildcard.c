#include <stdio.h>
#include <string.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    char s[n+1];
    char p[m+1];
    scanf("%s",s);
    scanf("%s",p);
    int dp[n+1][m+1];
    // dp[i][j] is boolean representing if first i characters of S match with first j characters of p
    FL(i,0,n+1){
        FL(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1; // Empty string matches empty pattern

    FL(j,1,m+1){// An empty string can only match a pattern if that pattern consists entirely of stars
        if(p[j-1] == '*'){ 
            dp[0][j] = dp[0][j - 1];
        }
    }
    FL(i,1,n+1){
        FL(j,1,m+1){
            // if characters match or pattern is ? diagonally
            if(p[j-1] == '?' || s[i-1] == p[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            // if star look up / left
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    if (dp[n][m]==1){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}