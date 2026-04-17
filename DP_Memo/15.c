#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 15: Max Subarray Sum with Single Mutation
Problem Description:
Given an array A of N integers, compute the maximum contiguous subarray sum.
You are permitted to square exactly one element within the chosen contiguous subarray to
maximize the total sum.
The solution must utilize a Divide and Conquer approach by returning multiple states for each
segment across recursive calls.
Expected Time Complexity: O(N logN)
Input Format:
Line 1: One integer N (Size of the array A, 2 ≤ N ≤ 10^4)
Line 2: N integers (Array A elements, -10^3 ≤ A[i] ≤ 10^3)
Output Format:
Maximum contiguous subarray sum after squaring a single element*/
ll max2(ll a, ll b) { return a > b ? a : b; }
ll max3(ll a, ll b, ll c) { return max2(a, max2(b, c)); }
ll max4(ll a, ll b, ll c, ll d){ return max2(max2(a,b), max2(c,d)); }

typedef struct {
    ll sum, sum1;
    ll pref0, suff0, best0;
    ll pref1, suff1, best1;
} Node;

Node solve(ll A[],int left,int right){
    if(left == right){
        Node N;
        ll val = A[left];
        ll sq = val * val;
        N.sum = val;
        N.sum1 = sq;
        N.pref0 = N.suff0 = N.best0 = val;
        N.pref1 = N.suff1 = N.best1 = sq;
        return N;
    }
    int mid = left + (right - left) / 2;
    Node L = solve(A, left, mid);
    Node R = solve(A, mid + 1, right);
    

    Node N;
    N.sum = L.sum + R.sum;
    N.sum1 = MAX(L.sum1 + R.sum,L.sum + R.sum1);
    
    N.pref0 = max2(L.pref0, L.sum + R.pref0);
    N.suff0 = max2(R.suff0,R.sum + L.suff0);
    N.pref1 = max3(L.pref1,L.sum1 + R.pref0,L.sum + R.pref1);
    N.suff1 = max3(R.suff1,R.sum1 + L.suff0,R.sum + L.suff1);

    N.best0 = max3(L.best0, R.best0, L.suff0 + R.pref0);
    N.best1 = max4(L.best1, R.best1, L.suff0 + R.pref1, L.suff1 + R.pref0);
    return N;
}
int main() {
    int n;
    scanf("%d", &n);
    
    ll A[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    
    // Run the divide and conquer
    Node final_result = solve(A, 0, n - 1);
    
    printf("%lld\n", final_result.best1);
    
    return 0;
}