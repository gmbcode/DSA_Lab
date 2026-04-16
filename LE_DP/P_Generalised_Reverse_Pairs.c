#include <stdio.h>
#include <stdlib.h>

// Function that handles both the counting and merging
int mergeAndCount(int arr[], int temp[], int left, int mid, int right, int K) {
    int count = 0;
    int j = mid + 1;

    // PHASE 1: The Counting Phase
    for (int i = left; i <= mid; i++) {
        // While the right element multiplied by K is strictly smaller
        while (j <= right && arr[i] > K * arr[j]) {
            j++;
        }
        // Add all valid elements found before j
        count += (j - (mid + 1));
    }
    // PHASE 2: The Standard Merge Phase
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;
}

// Core Divide and Conquer function
int mergeSortAndCount(int arr[], int temp[], int left, int right, int K) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(arr, temp, left, mid, K);
        count += mergeSortAndCount(arr, temp, mid + 1, right, K);
        count += mergeAndCount(arr, temp, left, mid, right, K);
    }
    return count;
}

int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int temp[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = mergeSortAndCount(arr, temp, 0, n - 1, k);
    printf("%d\n", ans);
    free(arr);
    free(temp);
    return 0;
}