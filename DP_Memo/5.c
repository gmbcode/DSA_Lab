#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
//Rev
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_N 1005
#define MAX_K 1005
int memo[MAX_N][MAX_K][2];
int prices[MAX_N];
int n;
/*
Question 5: Best Time to Buy and Sell Stock IV
Problem Description:
You are given an array of N integers where the ith element represents the price of a stock on
day i.
You are also given an integer K representing the maximum number of transactions allowed. A
transaction consists of buying and then selling one share of the stock.
Your task is to determine the maximum profit that can be achieved.
Note: You may not hold multiple stocks at once (you must sell before buying again).
Input Format:
Line 1: Two integers N and K
Line 2: N integers (stock prices)
Output Format:
Print a single integer representing the maximum profit
*/
int solve(int day,int t,int h){// day is day t is transactions h is holding
    if(day == n || t == 0){
        return 0;
    }
    if(memo[day][t][h] != -1){
        return memo[day][t][h];
    }
    int max_profit = 0;
    if(h == 1){
        int sell = prices[day] + solve(day + 1,t-1,0);
        int skip = solve(day + 1,t,1);
        max_profit = MAX(sell,skip);
    }
    else{
        int buy = -prices[day] + solve(day + 1,t,1);
        int skip = solve(day+1,t,0);
        max_profit = MAX(buy,skip);
    }
    memo[day][t][h] = max_profit;
    return max_profit;

}
int main(){
    int k;
    scanf("%d %d",&n,&k);
    FL(i,0,n){
        scanf("%d",&prices[i]);
    }
    memset(memo, -1, sizeof(memo));

    printf("%d\n",solve(0,k,0));

}