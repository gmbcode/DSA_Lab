#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

int ispeak(int n,int a[],int index);
int bin_search(int n,int a[]);
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    FL(i,0,n){
        scanf("%d",&arr[i]);
    }
    printf("%d",bin_search(n,arr));
}

int ispeak(int n,int a[],int index){
    if(index == n-1){
        return a[index] > a[index-1];
    }
    else if(index == 0){
        return a[index] > a[index+1];
    }
    else{
        return (a[index] > a[index-1]) && (a[index] > a[index+1]);
    }
}

int bin_search(int n,int a[]){
    int lo = 0;
    int hi = n-1;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(ispeak(n,a,mid)){
            return mid;
        }
        else if(a[mid] < a[mid+1]){
            lo = mid +1;
        }
        else{
            hi = mid - 1;
        }
    }
    return -1;
}


