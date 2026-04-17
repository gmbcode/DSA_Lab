#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 3: Cryptographic Subsequence Extraction
Problem Description
You are working on a decryption algorithm. You are given two non-empty strings: a Source
string and a Target string. Your task is to determine the total number of distinct ways to form the
Target string from the Source string. A Target string can be formed by deleting zero or more
characters from the Source string without changing the relative order of the remaining
characters. Two derivations are considered distinct if they differ in the set of indices removed
from the Source string.
*/
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char s1[n+1];
    char s2[m+1];
    scanf("%s",s1);
    scanf("%s",s2);
    int dp[n+1][m+1];
    if(n < m){
        printf("%d\n",0);
        return 0;
    }
    FL(i,0,n+1){
        FL(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    FL(i,0,n+1){ // Base case 1
        dp[i][0] = 1;
    }
    FL(j,1,m+1){// Base case 2
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