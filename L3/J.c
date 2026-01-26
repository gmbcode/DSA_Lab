#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(){
    int n, m;

    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);
    int b[m];
    for(int i = 0; i < m; i++){
        scanf("%d",&b[i]);
    }

    int *mn = a, *mx = b;
    int smallSize = n, largeSize = m;
    
    if (n > m) {
        mn = b; smallSize = m;
        mx = a; largeSize = n;
    }
    
    int lo = 0;
    int hi = smallSize;
    double median = 0.0;
    
    while(lo <= hi){
        int part1 = (lo + hi) / 2;
        int part2 = (smallSize + largeSize + 1) / 2 - part1;

        int l1 = (part1 == 0) ? INT_MIN : mn[part1 - 1];
        int r1 = (part1 == smallSize) ? INT_MAX : mn[part1];

        int l2 = (part2 == 0) ? INT_MIN : mx[part2 - 1];
        int r2 = (part2 == largeSize) ? INT_MAX : mx[part2];

        if(l1 <= r2 && l2 <= r1){
            if ((smallSize + largeSize) % 2 == 0) {
                median = (double)(MAX(l1, l2) + MIN(r1, r2)) / 2.0;
            } else {
                median = (double)MAX(l1, l2);
            }
            break;
        }
        else if(l1 > r2){
            hi = part1 - 1;
        }
        else{
            lo = part1 + 1;
        }
    }
    
    printf("%.2f\n", median);
    return 0;
}