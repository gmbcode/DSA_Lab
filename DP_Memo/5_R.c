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

int memo[MAX_N][MAX_N][2];
int n,k;
int stock[MAX_N];

int solve(int d,int t,int h){
    if(d == n || t == 0){
        return 0;
    }
    if(memo[d][t][h] != -1){
        return memo[d][t][h];
    }
    if(h){ // if holding stock
        int sell = stock[d] + solve(d+1,t-1,0);
        int hold = solve(d+1,t,1);
        return memo[d][t][h] = MAX(sell,hold);
    }
    else{
        int buy = -stock[d] + solve(d+1,t,1);
        int skip = solve(d+1,t,0);
        return memo[d][t][h] = MAX(buy,skip);
    }
}
int main(){
    scanf("%d %d",&n,&k);
    FL(i,0,n){
        scanf("%d",&stock[i]);
    }
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(0,k,0));
}

