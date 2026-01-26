#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ll long long

int checkShip(int n, int weights[], int D, int capacity);

int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[n];
    int lo = 0;
    int hi = 0;
    int mid;
    int ans = hi;
    FL(i,0,n){
        scanf("%d",&a[i]);
        lo = MAX(lo,a[i]);
        hi += a[i];
    }
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(checkShip(n,a,d,mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    printf("%d\n",ans);


}
int checkShip(int n, int weights[], int D, int capacity){
    int daysNeeded = 1;
    int currentLoad = 0;
    FL(i,0,n){
        if (currentLoad + weights[i] > capacity) {
            daysNeeded++; 
            currentLoad = weights[i]; 
        } else {
            currentLoad += weights[i];
        }
    }
    return daysNeeded <= D;
}