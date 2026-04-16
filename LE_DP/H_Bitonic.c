#include <stdio.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)


void reverse(int a[], int n){
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
    
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int a[n];
    FL(i,0,n){
        scanf("%d", &a[i]);
    }
    

    int dp1[n];
    int dp2[n];
    
    FL(i,0,n){
        dp1[i] = 1;
        dp2[i] = 1;
    }
    
    FL(i,0,n){
        FL(j,0,i){
            if(a[j] < a[i]){
                dp1[i] = MAX(dp1[i], 1 + dp1[j]); 
            }
        }
    }
    
    reverse(a, n);
    
    FL(i,0,n){
        FL(j,0,i){
            if(a[j] < a[i]){
                dp2[i] = MAX(dp2[i], 1 + dp2[j]); 
            }
        }
    }
    
    reverse(dp2, n);
    

    int ans = 0;
    FL(i,0,n){
        ans = MAX(ans, dp1[i] + dp2[i] - 1);
    }
    
    printf("%d\n", ans);
    return 0;
}