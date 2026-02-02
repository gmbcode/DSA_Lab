#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long
int get1(int n);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    int tmp;
    FL(i,0,n){
        FL(j,1,n-i){
            if(get1(a[j]) > get1(a[j-1])){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;           
            }
            else if(get1(a[j]) == get1(a[j-1])){
                if(a[j] > a[j-1]){
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;                   
                }
            }
        }
    }
    FL(i,0,n){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int get1(int n){
    int ans = 0;
    int index = 0;
    while(index <= 10){
        if((n >> index) & 1){
            ans++;
        }
        index++;
    }
    return ans;
}