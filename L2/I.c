#include<stdlib.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

void bubblesort(int n,int a[]){
    int temp;
    FL(i,0,n){
        FL(j,1,n-i){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    bubblesort(n,a);
    int ec = 0;
    int oc = 0;
    FL(i,0,n){
        if(i % 2 == 0 && a[i] % 2 == 0){
            ec++;
        }
        else if(i % 2 != 0 && a[i] % 2 != 0){
            oc++;
        }
    }
    printf("%d, %d",ec,oc);
    
}