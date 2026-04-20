#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
int merge(int a[],int tmp[],int left,int right){
    int mid = (left + right) / 2;
    int cp1 = left;
    int cp2 = mid + 1;
    int ct = 0;
    while(cp1 <= mid){
        while(cp2 <= right && a[cp1] > 2*a[cp2]){
            cp2++;
        }
        ct += ((cp2) - (mid + 1));
        cp1++;        
    }
    int p1 = left;
    int p2 = mid + 1;
    int p3 = left;
    while(p1 <= mid && p2 <= right){
        if(a[p1] > a[p2]){
            tmp[p3++] = a[p2++];
        }
        else{
            tmp[p3++] = a[p1++];
        }
    }
    while (p1 <= mid)
    {
        tmp[p3++] = a[p1++];
    }
    while(p2 <= right){
        tmp[p3++] = a[p2++];
    }
    for (int i = left; i <= right; i++) {
        a[i] = tmp[i];
    }
    return ct;
}

int mergeSort(int a[],int tmp[],int left,int right){
    if(left >= right){
        return 0;
    }
    else{
        int mid = (left + right) / 2;
        int st = 0;
        st += mergeSort(a,tmp,left,mid);
        st += mergeSort(a,tmp,mid+1,right);
        st += merge(a,tmp,left,right);
        return st;
    }
}

int main(){
    int  n;
    scanf("%d",&n);
    int a[n];
    int tmp[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    printf("%d\n",mergeSort(a,tmp,0,n-1));
}