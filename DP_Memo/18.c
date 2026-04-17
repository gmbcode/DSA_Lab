#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 18: Count of Range Sum
Problem Description:
You are given an array A of N integers and two integers lower and upper.
Your task is to count the number of subarrays whose sum lies in the inclusive range [lower,
upper].
Formally, count the number of pairs (i, j) such that:
● 0 ≤ i ≤ j < N
● lower ≤ sum(A[i...j]) ≤ upper
The solution must be implemented using a Divide and Conquer approach.
Brute-force solutions will not be accepted.
Input Format:
Line 1: Three integers N, lower, upper
Line 2: N integers (Array A elements)
*/
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
int main(){
    int n,lower,upper;
    scanf("%d %d %d",&n,&lower,&upper);
    int a[n];
    int prefix[n+1];
    int temp[n];
    prefix[0] = 0;
    FL(i,0,n){
        scanf("%d",&a[i]);
        prefix[i + 1] = prefix[i] + a[i];
    }
    int total_valid_subarrays = mergeSortAndCount(prefix, temp, 0, n, lower, upper);
    printf("%d\n", total_valid_subarrays);
    
}