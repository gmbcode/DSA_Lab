#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
/*
Question 4: Circular Energy
Problem Description:
You are the chief engineer of a starship with a circular power grid. Each power module has a
specific integer energy_output.
Because the grid is circular, the first and last modules are adjacent. To prevent a catastrophic
overload, no two adjacent modules can be activated simultaneously.
Given an integer array energy_output, return the maximum total energy you can safely
generate without triggering an overload.
*/
void reverse(int a[],int n){
    int p1 = 0;
    int p2 = n-1;
    int tmp;
    while(p1 < p2){
        tmp = a[p1];
        a[p1] = a[p2];
        a[p2] = tmp;
        p1++;
        p2--;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    if (n == 1) {
        int v;
        scanf("%d", &v);
        printf("%d\n", v);
        return 0;
    }
    int dp1[n];
    int dp2[n];
    FL(i,0,n){
        dp1[i] = 0;
        dp2[i] = 0;
    }
    dp1[0] = 0;
    dp1[1] = a[0];
    FL(i,2,n){
        dp1[i] = MAX(a[i-1] + dp1[i-2],dp1[i-1]);
    }
    reverse(a,n);
    dp2[0] = 0;
    dp2[1] = a[0];
    FL(i,2,n){
        dp2[i] = MAX(a[i-1] + dp2[i-2],dp2[i-1]);
    }
    printf("%d\n",MAX(dp1[n-1],dp2[n-1]));


}