#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

int iib(int i,int j,int m,int n){
    if((i >= 0 && i < m) && (j >= 0 && j < n)){
        return 1;
    }
    return 0;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int grid[m][n];
    FL(i,0,m){
        FL(j,0,n){
            scanf("%d",&grid[i][j]);
        }
    }
    int dp[m][n];
    
    int psum;
    FL(i,0,m){
        FL(j,0,n){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1; // Base case
    FL(i,0,m){
        FL(j,0,n){
            if (i == 0 && j == 0){
                continue; 
            }
            if(!grid[i][j]){
                psum = 0;
                if(iib(i-1,j,m,n)){
                    psum += dp[i-1][j];
                }   
                if(iib(i,j-1,m,n)){
                    psum += dp[i][j-1];
                }
                dp[i][j] = psum;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    printf("%d\n",dp[m-1][n-1]);

}