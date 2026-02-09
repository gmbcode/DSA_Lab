#include <stdio.h>
#include <stdlib.h>
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define F_INV(i,a,b) for(int i = a; i >= b ; i--)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int MX(int n,int a[]) {
    int max = a[0];
    FL(i,0,n){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

void countSort(int n,int a[],int exp){
    int count[10] = {0};
    int tmp[n];
    FL(i,0,n){
        count[(a[i] / exp) % 10]++;
    }
    // Make cumulative count (so each count corresponds to pos in sorted arr)
    FL(i,1,10){
        count[i] += count[i-1];
    }

    F_INV(i,n-1,0){
        tmp[ (count[(a[i] / exp) % 10]-- )- 1] = a[i];
    }
    FL(i,0,n){
        a[i] = tmp[i];
    }
}

void radixSort(int n,int a[]){
    int mx = MX(n,a);
    for(int i = 1 ; (mx / i) > 0 ; i *= 10){
        countSort(n,a,i);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    radixSort(n, a);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


