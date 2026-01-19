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
    int na;
    scanf("%d",&na);
    int a[na];
    int b[na+2];
    FL(i,0,na){
        scanf("%d",&a[i]);
    }
    FL(i,0,na+2){
        scanf("%d",&b[i]);
    }
    bubblesort(na,a);
    bubblesort(na+2,b);
    int p1 = 0;
    int p2 = 0;
    while(p2 < na + 2){
        if(p1 < na && p2 < na+2){
            if(a[p1] == b[p2]){
                p1++;
                p2++;
            }
            else{
                printf("%d ",b[p2]);
                p2++;
            }
        }
        else if(p1 >= na){
            printf("%d ",b[p2]);
            p2++;
        }
    }
    printf("\n");

}