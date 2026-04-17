#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
/*
Question 16: Generalized Reverse Pairs
Problem Description:
Given an array A of N integers and an integer multiplier K. Determine the total number of
"important reverse pairs".
An index pair (i, j) is defined as an important reverse pair if and only if:
i < j and A[i] > K * A[j]
The solution must be implemented by modifying the Merge Sort algorithm.
Standard brute-force comparisons are strictly prohibited.
Expected Time Complexity: O(N logN)*/
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int merge(int* arr,int* tmp,int left,int right,int k){
    int p1 = left;
    int mid = (left + right) / 2;
    int p2 = mid + 1;
    int p3 = left;
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[i] > k * arr[j]) {
            j++;
        }
        // Add all valid elements found before j
        count += (j - (mid + 1));
    }

    while(p1 <= mid && p2 <= right){
        if(arr[p1] > arr[p2]){
            tmp[p3++] = arr[p2++];
        }
        else{
            tmp[p3++] = arr[p1++];
        }
    }
    while(p1 <= mid){
        tmp[p3++] = arr[p1++];
    }
    while(p2 <= right){
        tmp[p3++] = arr[p2++];
    }

    p3 = left;
    while(p3 <= right){
        arr[p3] = tmp[p3];
        p3++;
    }
    return count;
}
int mergeSort(int* arr,int* tmp,int left,int right,int k){
    if(left == right){
        return 0;
    }
    else{
        int mid = (left + right) / 2;
        int cnt = 0;
        cnt += mergeSort(arr,tmp,left,mid,k);
        cnt += mergeSort(arr,tmp,mid+1,right,k);
        cnt += merge(arr,tmp,left,right,k);
        return cnt;
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    int tmp[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    printf("%d\n",mergeSort(a,tmp,0,n-1,k));
}