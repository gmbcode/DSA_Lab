#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long


void mergesort(int n,int a[],int temp[],int l,int r);
void merge(int n,int a[],int temp[],int l,int r);

int main(){
    int n,k;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int temp[n];
    mergesort(n,a,temp,0,n-1);
    
    printf("%d\n",a[n-k]);

}

void mergesort(int n,int a[],int temp[],int l,int r){
    if(l == r){
        return;
    }
    int mid;
    if(l < r){
        mid = (l+r) / 2;
        mergesort(n,a,temp,l,mid);
        mergesort(n,a,temp,mid+1,r);
        merge(n,a,temp,l,r);
    }
}

void merge(int n,int a[],int temp[],int l,int r){
    int mid = (l+r) / 2;
    int p1 = l;
    int p2 = mid + 1;
    int index = l;
    while(p1 <= mid && p2 <= r){
        if(a[p1] < a[p2]){
            temp[index++] = a[p1++];
        }
        else{
            temp[index++] = a[p2++];
        }
    }

    while(p1 <= mid){
        temp[index++] = a[p1++];
    }
    while(p2 <= r){
        temp[index++] = a[p2++];
    }

    index = l;
    while(index <= r){
        a[index] = temp[index];
        index++;
    }
}