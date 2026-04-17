#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
/*
Question 9: Same DNA
Problem Description:
You are a bioinformatics researcher analyzing two DNA sequences, represented as strings
SeqA and SeqB.
You need to determine the minimum number of operations required to mutate SeqA exactly into
SeqB. You are permitted three operations on any character in SeqA:
1. Insert a character
2. Delete a character
3. Replace a character
Given the two strings SeqA and SeqB, return the minimum number of operations required to
achieve the mutation.*/
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_LEN 2005

int memo[MAX_LEN][MAX_LEN];
char a[MAX_LEN];
char b[MAX_LEN];
int n, m;

int solve(int i,int j){
    if(i == n){
        return m - j;
    }
    if(j == m){
        return n - i;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(a[i] == b[j]){
        return memo[i][j] = solve(i+1,j+1);
    }
    else{
        int insert = 1 + solve(i,j+1);
        int replace = 1 + solve(i+1,j+1);
        int delete = 1 + solve(i+1,j);
        memo[i][j] = MIN(insert,MIN(replace,delete));
        return memo[i][j];
    }
}
int main(){
    scanf("%d %d",&n,&m);
    scanf("%s",a);
    scanf("%s",b);
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(0,0));
}