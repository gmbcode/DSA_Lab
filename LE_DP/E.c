#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (n == 0 || k == 0) {
        printf("0\n");
        return 0;
    }
    
    int stock[n];
    FL(i,0,n){
        scanf("%d", &stock[i]);
    }
    
    int dp[n][k+1][2]; 
    
    // Initialize everything. 
    // We set holding [1] to a highly negative number so it doesn't accidentally
    // get chosen by the MAX function before we've actually bought a stock.
    FL(i, 0, n){
        FL(j, 0, k+1){
            dp[i][j][0] = 0;
            dp[i][j][1] = -1000000000; 
        }
    }

    // Base Case: Day 0
    // Start at 1 because 0 transactions = 0 profit.
    FL(j, 1, k+1){
        dp[0][j][0] = 0; 
        dp[0][j][1] = -stock[0]; 
    }

    FL(i, 1, n){
        FL(j, 1, k+1){
            dp[i][j][0] = MAX(dp[i-1][j][0], dp[i-1][j][1] + stock[i]);
            dp[i][j][1] = MAX(dp[i-1][j][1], dp[i-1][j-1][0] - stock[i]); 
        }
    }
    
    printf("%d\n", dp[n-1][k][0]);

    return 0;
}