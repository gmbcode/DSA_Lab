// O(Mlog(N)) approach - 1
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
    int key;
    FL(i,0,m){
        FL(j,0,n){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&key);
    int c_mx = -1;
    int r_mx = -1;
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(a[0][mid] <= key){
            c_mx = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }// We find index shorter than or equal to the max column that we will need to search
    lo = 0;
    hi = m - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(a[mid][0] <= key){
            r_mx = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }// We find index shorter than or equal to the max row that we will need to search
    if(c_mx == -1 || r_mx == -1){
        printf("-1\n");
        return 0;
    }
    // Now we can run binary search again on each of the rows
    int ansf = 0;
    int ansr = 0;
    int ansc = 0;
    FE(i,0,r_mx){
        lo = 0;
        hi = c_mx;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2 ;
            if(a[i][mid] == key){
                ansf = 1;
                ansr = i;
                ansc = mid;
                break;
            }
            else if(a[i][mid] > key){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    if(!ansf){
        printf("-1\n");
        return 0;  
    }
    else{
        printf("%d %d\n",ansr,ansc);
        return 0;
    }

}
