#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
//Rev
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 8: Longest Bitonic Subsequence
Problem Description:
You are given an array of N integers.
A Bitonic Subsequence is a sequence that first strictly increases and then strictly decreases.
Your task is to determine the length of the longest bitonic subsequence in the given array.
Note: Either increasing or decreasing part can be empty, but the sequence must have at least
one element.
Input Format:
Line 1: One integer N
Line 2: N integers (array elements)
Output Format:
Print a single integer representing the length of the longest bitonic subsequence.
*/
void reverse(int a[],int n){
    int p1 = 0;
    int p2 = n-1;
    int tmp;
    while(p1 < p2){
        tmp = a[p1];
        a[p1] = a[p2];
        a[p2] = tmp;
        p1++;
        p2--;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int dp1[n];
    int dp2[n];
    FL(i,0,n){
        dp1[i] = 1;
        dp2[i] = 1;
    }

    FL(i,0,n){
        FL(j,0,i){
            if(a[j] < a[i]){
                dp1[i] = MAX(dp1[i],1+dp1[j]);
            }
        }
    }

    reverse(a,n);
    FL(i,0,n){
        FL(j,0,i){
            if(a[j] < a[i]){
                dp2[i] = MAX(dp2[i],1+dp2[j]);
            }
        }
    }
    reverse(dp2,n);

    int ans = 1;
    FL(i,0,n){
        ans = MAX(ans,dp1[i] + dp2[i] - 1);
    }
    printf("%d\n",ans);

    


}