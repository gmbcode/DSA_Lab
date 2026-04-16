#include <stdio.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX3(a, b, c) MAX(MAX(a, b), c)
#define FL(i,a,b) for(int i = a ; i < b ; i++)
// Function to find the maximum subarray sum crossing the midpoint
int maxCrossingSum(int A[], int left, int mid, int right) {
    int sum = 0;
    
    // Scan backward into the left half to find the best prefix touching the middle
    int left_max = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += A[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }
    sum = 0;
    
    // Scan forward into the right half to find the best suffix touching the middle
    int right_max = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += A[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }

    return left_max + right_max;
}

// Core Divide and Conquer function
int maxSubArraySum(int A[], int left, int right) {
    if (left == right) {
        return A[left];
    }
    int mid = left + (right - left) / 2;
    int max_left = maxSubArraySum(A, left, mid);
    int max_right = maxSubArraySum(A, mid + 1, right);
    int max_cross = maxCrossingSum(A, left, mid, right);

    // Return the maximum of all three possibilities
    return MAX3(max_left, max_right, max_cross);
}

int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    FL(i,0,n){
        scanf("%d", &a[i]);
    }
    int max_sum = maxSubArraySum(a, 0, n-1);
    printf("%d\n", max_sum);
    return 0;
}