#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main(){
    int n;
    scanf("%d",&n);
    if (n == 1) {
        int v;
        scanf("%d", &v);
        printf("%d\n", v);
        return 0;
    }
    int energy[n];
    FL(i,0,n){
        scanf("%d",&energy[i]);
    }
    int dp1[n];
    int dp2[n];
    dp1[0] = 0;
    dp1[1] = energy[0];
    // First and last towers cannot be on simultaneously giving us two cases
    // Case 1 -> First tower is used and last ignored
    // Case 2 -> Last is used first is ignored
    // This gives us two linear dp solutions we take max of which
    // let dp1[i] denote solution for i towers case 1
    // dp1[i] = MAX(dp[i-2] + energy[i-1],dp[i-1])
    FL(i,2,n){
        dp1[i] = MAX(dp1[i-2] + energy[i-1],dp1[i-1]);
    }
    int a1 = dp1[n-1];
    int tmp;
    FL(i,0,n/2){
        tmp = energy[i];
        energy[i] = energy[n-i-1];
        energy[n-i-1] = tmp;
    }
    dp2[0] = 0;
    dp2[1] = energy[0];
    FL(i,2,n){
        dp2[i] = MAX(dp2[i-2] + energy[i-1],dp2[i-1]);
    }
    int a2 = dp2[n-1];
    printf("%d\n",MAX(a1,a2));
}