#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 13: The Cybernetic Bidding War
Problem Description:
Two advanced trading algorithms, Alpha and Beta, are competing in a high-stakes auction. A
sequence of N high-value data caches is laid out in a straight line. Each cache has a specific
monetary value.
The rules of the auction are strict:
1. Alpha and Beta take turns. Alpha always goes first.
2. On their turn, an algorithm can only select and take exactly one data cache, and it must
be from either the extreme left or the extreme right of the remaining line.
3. Both algorithms are perfectly logical, possess complete information, and play optimally.
Alpha plays to maximize its own score, while Beta plays to maximize its own score. The
game is zero-sum: maximizing one player's score minimizes the other's.
Calculate the maximum value Alpha can guarantee assuming both players play optimally.
*/
int main(){
    int n;
    scanf("%d",&n);
    int cache[n];
    FL(i,0,n){
        scanf("%d",&cache[i]);
    }
    int dp[n][n];

    FL(i,0,n){
        FL(j,0,n){
            dp[i][i] = cache[i];
        }
    }
    FL(i,0,n-1){
        dp[i][i+1] = MAX(cache[i],cache[i+1]);
    }

    FL(len,3,n+1){
        FL(i,0,n-len+1){
            int j = i + len - 1;

            int t_left = cache[i] + MIN(dp[i+2][j],dp[i][j-1]);
            // Max value if we take left and opponent plays optimally
            int t_right = cache[j] + MIN(dp[i][j-2],dp[i+1][j-1]);

            dp[i][j] = MAX(t_left,t_right);
        }
    }
    printf("%d\n",dp[0][n-1]);

}