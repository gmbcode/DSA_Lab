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
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    bubblesort(n,a);
    int ct = 1;
    int maxct = 0;
    FL(i,0,n){
        ct = 1;
        int start = i;
        int end = i+1;
        while(end < n){
            if(a[end] - a[start] > k){
                break;
            }
            if(a[end] - a[start] <= k){
                ct++;
            }
            end++;
        }
        if(ct > maxct){
            maxct = ct;
        }

    }
    printf("%d\n",maxct);
    
}