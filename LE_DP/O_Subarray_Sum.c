#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define MIN_VAL -2000000000

int max2(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) { return max2(a, max2(b, c)); }

// Global arrays for memoization
int memo[10005][2];
int visited[10005][2];
int A[10005];

// solve(i, state) returns the max contiguous sum ending EXACTLY at index i
int solve(int i, int state) {
    // Base Case: The very first element
    if (i == 0) {
        if (state == 0) return A[0];
        if (state == 1) return A[0] * A[0];
    }

    // If we have already calculated this exact state, return it immediately
    if (visited[i][state]) {
        return memo[i][state];
    }

    int ans;
    int val = A[i];
    int sq = val * val;

    if (state == 0) {
        // Normal state choices
        ans = max2(val, solve(i - 1, 0) + val);
    } else {
        // Mutated state choices
        ans = max3(sq, solve(i - 1, 0) + sq, solve(i - 1, 1) + val);
    }

    // Save to cache before returning
    visited[i][state] = 1;
    memo[i][state] = ans;
    
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize visited array to 0 (false)
    for (int i = 0; i < n; i++) {
        visited[i][0] = 0;
        visited[i][1] = 0;
    }

    int global_best = MIN_VAL;

    // The maximum subarray could end at ANY index. 
    // We must check the best mutated sum ending at every possible 'i' 
    // and find the absolute maximum among them.
    for (int i = 0; i < n; i++) {
        global_best = max2(global_best, solve(i, 1));
    }

    printf("%d\n", global_best);

    return 0;
}