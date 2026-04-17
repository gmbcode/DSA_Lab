#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
/*
Question 10: Optimised Cuts
Problem Description:
You are a structural engineer fabricating a specialized titanium beam of overall length N.
You are given an integer array cuts representing specific positions along the beam where you
must make precision cuts.
The cost of making a cut is strictly equal to the length of the beam segment being cut.
When a cut is made, the beam is permanently split into two smaller, independent segments.
You can perform the cuts in any order you choose.
Given the integer N and the array cuts, return the minimum total cost required to perform all the
necessary cuts.
Input Format:
Line 1: Two integers N, M (Size of the beam initially, Number of cuts to be made)
Line 2: M integers (Cutting Position)
*/
// Define max constraints. Usually M is <= 100 for this problem.
#define MAX_M 105
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int memo[MAX_M][MAX_M];
int cuts[MAX_M];

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Recursive function with memoization
int solve(int left, int right) {
    // Base Case: No cuts left to make between these two indices
    if(right - left <= 1){
        return 0;
    }
    if(memo[left][right] != -1){
        return memo[left][right];
    }
    int min_cost = INT_MAX;
    int cost;
    for(int i = left + 1; i < right ; i++){
        cost = (cuts[right] - cuts[left]) + solve(left,i) + solve(i,right);
        min_cost = MIN(min_cost,cost);
    }
    return memo[left][right] = min_cost;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // We pad the array. Index 0 is the start of the beam (0).
    cuts[0] = 0;
    
    // Read the actual cuts
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cuts[i]);
    }
    
    // The last element is the end of the beam (N).
    cuts[m + 1] = n;

    qsort(cuts, m + 2, sizeof(int), compare);

    memset(memo, -1, sizeof(memo));

    printf("%d\n", solve(0, m + 1));

    return 0;
}