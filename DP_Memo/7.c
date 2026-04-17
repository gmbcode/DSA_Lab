#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
//Rev
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_LEN 2005
/*
Question 7: Wildcard Matching
Problem Description:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for
'?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Input Format:
Line 1: Two integers N and M (length of string S and pattern P)
Line 2: String S
Line 3: String P
Output Format:
Print YES if the string matches the pattern, otherwise print NO.*/
int memo[MAX_LEN][MAX_LEN];
char s[MAX_LEN];
char p[MAX_LEN];
int n, m;

int solve(int i,int j){
    if(i == n && j == m){
        return 1;
    }
    if(j == m){
        return 0;
    }
    if(i == n){
        for(int k = j ; k < m ; k++){
            if(p[k] != '*'){
                return 0;
            }
        }
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(p[j] == '?' || s[i] == p[j]){
        memo[i][j] = solve(i+1,j+1);
        return memo[i][j];
    }
    else if(p[j] == '*'){
        return memo[i][j] = (solve(i+1,j) || solve(i,j+1));
    }

    return memo[i][j] = 0;
}
int main(){
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    scanf("%s",p);
    memset(memo, -1, sizeof(memo));

    if(solve(0,0)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

}