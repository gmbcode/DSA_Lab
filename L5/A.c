#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    FL(i,0,m){
        FL(j,0,n){
            scanf("%d",&a[i][j]);
        }
    }
    int a1,b1,a2,b2;
    scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
    int pref[m][n];
    FL(i,0,m){
        FL(j,0,n){
            pref[i][j] = a[i][j]; 
            if(i > 0) pref[i][j] += pref[i-1][j];
            if(j > 0) pref[i][j] += pref[i][j-1];
            if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }
    }
    FL(i,0,m){
        FL(j,0,n){
            printf("%d ",pref[i][j]);
        }
        printf("\n");
    }
    a1--;
    b1--;
    a2--;
    b2--;
    // Offset to fix 1 based index
    int ans = pref[a2][b2];
    if(a1 > 0){
        ans -= pref[a1 - 1][b2];
    }
    if(b1 > 0){
        ans -= pref[a2][b1 - 1];
    }
    if(a1 > 0 && b1 > 0){
        ans += pref[a1 - 1][b1 - 1];
    }
    printf("%d\n",ans);

}
