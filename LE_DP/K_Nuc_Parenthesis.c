#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULTS 5000


typedef struct {
    long long vals[MAX_RESULTS];
    int count;
} ResultList;

ResultList* memo[20][20];


int cmpfunc(const void* a, const void* b) {
    long long diff = (*(long long*)a - *(long long*)b);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

// Divide and Conquer function
ResultList* compute(char* s, int left, int right) {
    // Return memoed / cached result 
    if (memo[left][right] != NULL) {
        return memo[left][right];
    }

    ResultList* res = (ResultList*) malloc(sizeof(ResultList));
    res->count = 0;

    // Base Case: If it's a single character, it's guaranteed to be a digit
    if (left == right) {
        res->vals[res->count++] = s[left] - '0'; // Convert char to integer
        memo[left][right] = res;
        return res;
    }

    // Operators are at odd indices wrt digits
    for (int i = left + 1; i <= right - 1; i += 2) {
        char op = s[i];
        
        // Recursively solve the left and right sub-expressions
        ResultList* leftResults = compute(s, left, i - 1);
        ResultList* rightResults = compute(s, i + 1, right);

        // Combine: Cartesian product of left and right results
        for (int l = 0; l < leftResults->count; l++) {
            for (int r = 0; r < rightResults->count; r++) {
                long long a = leftResults->vals[l];
                long long b = rightResults->vals[r];
                
                if (op == '+') res->vals[res->count++] = a + b;
                else if (op == '-') res->vals[res->count++] = a - b;
                else if (op == '*') res->vals[res->count++] = a * b;
            }
        }
    }

    // Cache the result
    memo[left][right] = res;
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    
    char s[25];
    scanf("%s", s);

    // Initialize memo table to NULL
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            memo[i][j] = NULL;
        }
    }

    ResultList* finalResults = compute(s, 0, n - 1);

    // The problem requires non-decreasing sorted order
    qsort(finalResults->vals, finalResults->count, sizeof(long long), cmpfunc);

    for (int i = 0; i < finalResults->count; i++) {
        printf("%lld", finalResults->vals[i]);
        if (i < finalResults->count - 1) {
            printf(" ");
        }
    }
    printf("\n");

}
