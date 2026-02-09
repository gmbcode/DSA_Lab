#include <stdio.h>
#include <stdlib.h>
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int getMax(int arr[], int n) {
    int max = arr[0];
    FL(i,0,n){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int i, count[10] = {0};


    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Make cumulative count
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    radixSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}