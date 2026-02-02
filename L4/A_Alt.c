// O(M + N) optimal approach for problem - 2
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int iib(int r,int c,int m,int n);

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    int key;
    FL(i,0,m){
        FL(j,0,n){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&key);
    int found = 0;
    int row = 0;
    int col = n - 1;
    while(iib(row,col,m,n)){
        if(a[row][col] == key){
            found = 1;
            break;
        }
        else if(a[row][col] > key){
            col--;
        }
        else{
            row++;
        }
    }
    found ? printf("%d %d\n",row,col) : printf("-1\n");
}

int iib(int r,int c,int m,int n){
    if((r < m && c < n) && (r >= 0 && c >= 0)){
        return 1;
    }
    else{
        return 0;
    }
}