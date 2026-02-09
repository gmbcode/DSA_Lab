#include <stdio.h>
#include <stdlib.h>
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

void bsort(int n,int a[]);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];

    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    bsort(n,a);

    int found = 0;
    FL(i,0,n-2){
        if(i > 0 && a[i] == a[i-1]){
            continue;
        }
        FL(j,i+1,n-1){
            if(j > i+1 && a[j] == a[j-1]){
                continue;
            }
            FL(k,j+1,n){
                if(k > j+1 && a[k] == a[k-1]){
                    continue;
                }
                int sum = a[i] + a[j] + a[k];
                if(sum == 0){
                    printf("%d %d %d\n",a[i],a[j],a[k]);
                    found = 1;
                }
            }
        }
    }
    if(!found){
        printf("No triplets found\n");
    }


}

void bsort(int n,int a[]){
    int tmp;
    FL(i,0,n){
        FL(j,1,n-i){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}