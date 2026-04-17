#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 105
#define INF 1000000000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int memo[MAX_N][MAX_N];
int pref[MAX_N];
int K;
/*
Question 20: Minimum Cost to Merge Stones
Problem Description:
You are given an array A of N integers, where A[i] represents the number of stones in the ith
pile. Your goal is to merge all these piles into exactly one pile. You are also given an integer K.
In one move, you can pick exactly K consecutive piles and merge them into a single pile.
The Rules
Consecutive Only: You can only merge piles that are adjacent to each other in the current array.
Cost: The cost of a single merge operation is the sum of all stones in the K piles being merged.
Result: The K piles are removed and replaced by one new pile containing their total sum.
Goal: Find the minimum total cost to reach a single pile. If it is impossible to merge the N piles
into one, return -1.
Input Format:
Line 1: Two integers N and K
Line 2: N integers (Array A elements)
Output Format:
Print a single integer representing the minimum cost to merge all piles into one. If not possible,
print -1.
*/
// Recursive function to find min cost to merge subarray as much as possible
int solve(int i, int j) {
    // Base Case: A single pile costs 0 to merge
    if (i == j) {
        return 0;
    }
    
    // Return cached result if already calculated
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int min_cost = INF;

    // Split the array. 
    // 'mid' jumps by (K - 1) to ensure the left part can always be reduced to exactly 1 pile.
    for (int mid = i; mid < j; mid += (K - 1)) {
        int left_cost = solve(i, mid);
        int right_cost = solve(mid + 1, j);
        
        if (left_cost != INF && right_cost != INF) {
            min_cost = MIN(min_cost, left_cost + right_cost);
        }
    }

    // If the entire current segment can be merged into 1 final pile...
    if ((j - i) % (K - 1) == 0) {
        // ...we add the cost of merging them together (which is the sum of their stones)
        min_cost += (pref[j + 1] - pref[i]);
    }

    return memo[i][j] = min_cost;
}

int main() {
    int n;
    
    // Read N and K
    if (scanf("%d %d", &n, &K) != 2) return 0;

    int a[MAX_N];
    pref[0] = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // Build prefix sum array to get quick range sums later
        pref[i + 1] = pref[i] + a[i];
    }

    // Feasibility Check: Can N piles be merged into 1 pile taking (K-1) piles per step?
    if ((n - 1) % (K - 1) != 0) {
        printf("-1\n");
        return 0;
    }

    // Initialize memoization table
    memset(memo, -1, sizeof(memo));

    // Calculate minimum cost for the entire array
    int ans = solve(0, n - 1);
    
    printf("%d\n", ans);

    return 0;
}