#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int cuts[m+2];
    FL(i,0,m){
        scanf("%d",&cuts[i+1]);
    }
    cuts[0] = 0;
    cuts[m+1] = n;
    int dp[m+2][m+2];
    qsort(cuts, m + 2, sizeof(int), cmpfunc); // Can replace with alt like  bsort
    FL(i,0,m+2){
        FL(j,0,m+2){
            dp[i][j] = 0;
        }
    }

    FL(len,2,m+2){
        FL(i,0,m+2-len){
            int j = i + len;
            dp[i][j] = INT_MAX;

            FL(k,i+1,j){
                int curr_cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                dp[i][j] = MIN(dp[i][j],curr_cost);
            }
        }
    }
    
    printf("%d\n",dp[0][m+1]);

}
