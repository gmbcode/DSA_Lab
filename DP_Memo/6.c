#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
//Rev
/*
Question 6: Longest Palindromic Subsequence
Problem Description:
You are given a string S of length N consisting of lowercase English letters.
Your task is to determine the length of the longest subsequence of S that forms a palindrome.
A subsequence is a sequence that can be derived from another sequence by deleting some or
no elements without changing the order of the remaining elements.
Input Format:
Line 1: One integer N
Line 2: A string S of length N
*/
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main(){
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int dp[n][n]; // dp[i][j] denotes length of lps starting at index i till index j
    FL(i,0,n){
        FL(j,0,n){
            dp[i][j] = 0;
        }
    }
    FL(i,0,n){
        dp[i][i] = 1;
    }
    FL(len,2,n+1){ // length of lps
        FL(i,0,n - len + 1){ // start of lps
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(len == 2){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
            }
            else{
                dp[i][j] = MAX(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",dp[0][n-1]);
}