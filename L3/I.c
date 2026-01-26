#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ll long long

ll merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left;    // Index for temp merged array
    ll inv_count = 0;

    while ((i <= mid) && (j <= right)) { // Normal merge sort loop
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j], so arr[i] and all of the subsequent elements in left subarray form inversions
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }


    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}


ll mergeSort(int arr[], int temp[], int left, int right) {
    ll inv_count = 0;
    if (right > left) {
        int mid = (right + left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ll ans = mergeSort(arr, temp, 0, n - 1);
    printf("%lld\n", ans);
    free(arr);
    free(temp);
    return 0;
}