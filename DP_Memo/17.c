#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 17: Maximum Subarray Sum (Divide and Conquer)
Problem Description:
You are given an array A of N integers (which may include negative values).
Your task is to compute the maximum possible sum of a contiguous subarray using a Divide and
Conquer approach.
The solution must divide the array into two halves recursively and consider:
● Maximum subarray entirely in left half
● Maximum subarray entirely in right half
● Maximum subarray crossing the midpoint
Input Format:
Line 1: One integer N (Size of the array)
Line 2: N integers (Array A elements)
Output Format:
Print a single integer representing the maximum subarray sum.
*/
int maxCrossSum(int* arr,int left,int mid,int right){
    int sum = 0;
    int lt_max = INT_MIN;
    int rt_max = INT_MIN;
    for(int i = mid ; i >= left ; i--){
        sum += arr[i];
        lt_max = MAX(lt_max,sum);
    }
    sum = 0;
    for(int i = mid+1 ; i <= right ; i++){
        sum += arr[i];
        rt_max = MAX(rt_max,sum);
    }

    return lt_max + rt_max;
}
int maxSubarrSum(int* arr,int left,int right){
    if(left == right){
        return arr[left];
    }
    else{
        int mid = (left + right) / 2;
        int lt_s = maxSubarrSum(arr,left,mid);
        int rt_s = maxSubarrSum(arr,mid+1,right);
        int cross = maxCrossSum(arr,left,mid,right);
        return MAX(lt_s,MAX(rt_s,cross));
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    printf("%d\n",maxSubarrSum(a,0,n-1));
}