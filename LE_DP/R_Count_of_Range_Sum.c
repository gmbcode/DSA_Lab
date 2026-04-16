#include <stdio.h>
#include <stdlib.h>

// Merge Sort and Count function using purely standard ints
int mergeSortAndCount(int* prefix, int* temp, int left, int right, int lower, int upper) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = 0;

    // 1. Recursively count left and right halves
    count += mergeSortAndCount(prefix, temp, left, mid, lower, upper);
    count += mergeSortAndCount(prefix, temp, mid + 1, right, lower, upper);

    // 2. The Counting Phase (Sliding Window)
    int start = left;
    int end = left;
    
    for (int j = mid + 1; j <= right; j++) {
        while (start <= mid && prefix[start] < prefix[j] - upper) {
            start++;
        }
        while (end <= mid && prefix[end] <= prefix[j] - lower) {
            end++;
        }
        count += (end - start);
    }

    // 3. The Standard Merge Phase
    int i = left;
    int j_merge = mid + 1;
    int k = left;

    while (i <= mid && j_merge <= right) {
        if (prefix[i] <= prefix[j_merge]) {
            temp[k++] = prefix[i++];
        } else {
            temp[k++] = prefix[j_merge++];
        }
    }
    while (i <= mid) {
        temp[k++] = prefix[i++];
    }
    while (j_merge <= right) {
        temp[k++] = prefix[j_merge++];
    }

    // Copy back to the original prefix array
    for (i = left; i <= right; i++) {
        prefix[i] = temp[i];
    }

    return count;
}

int main() {
    int n, lower, upper;
    
    scanf("%d %d %d", &n, &lower, &upper);

    // Allocate arrays as standard ints
    int* A = (int*)malloc(n * sizeof(int));
    int* prefix = (int*)malloc((n + 1) * sizeof(int));
    int* temp = (int*)malloc((n + 1) * sizeof(int));

    // Build the prefix sum array
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        prefix[i + 1] = prefix[i] + A[i];
    }

    // Run the Divide & Conquer
    int total_valid_subarrays = mergeSortAndCount(prefix, temp, 0, n, lower, upper);

    printf("%d\n", total_valid_subarrays);

    return 0;
}