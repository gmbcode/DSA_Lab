#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

// Monotonically decreasing queue
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[10000];
    FL(i, 0, n) {
        scanf("%d", &arr[i]);
    }

    int deque[10000]; 
    int front = 0;
    int rear = -1; 
    
    FL(i, 0, n) {
        // Remove indices that are out of the current sliding window
        if (front <= rear && deque[front] <= i - k) {
            front++; 
        }
        
        while (front <= rear && arr[deque[rear]] <= arr[i]){//Remove smaller elements from monotonic queue 
            rear--;
        }
        
        // Add current index to queue
        deque[++rear] = i;
        
        //After processing at least one window of elements we start printing answers
        if (i >= k - 1) {
            printf("%d ", arr[deque[front]]);
        }
    }
    printf("\n");
    
    return 0;
}