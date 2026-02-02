#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int isPossible(int a[], int n, int k, int time_limit);

typedef struct Interval{
    int start;
    int end;
} Interval;

void bsort(Interval a[],int n,int mode);

int main(){
    int n;
    scanf("%d",&n);
    Interval a[n];
    Interval tmp;
    FL(i,0,n){
        scanf("%d %d",&tmp.start,&tmp.end);
        a[i] = tmp;
    }
    bsort(a,n,0);
    bsort(a,n,1);
    int flag = 1;
    int current_max_reach = a[0].end;
    FL(i,1,n){
        if(a[i].start > current_max_reach){
            flag = 0;
        }
        current_max_reach = MAX(current_max_reach,a[i].end);
    }
    FL(i,0,n){
        printf("%d %d\n",a[i].start,a[i].end);
    }
    if(flag){
        printf("Contiguous\n");
    }
    else{
        printf("Fragmented\n");
    }
    

}

void bsort(Interval a[],int n,int mode){
    Interval tmp;
    if(mode){
        FL(i,0,n){
            FL(j,1,n-i){
                if(a[j].start == a[j-1].start && a[j].end < a[j-1].end){
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                }
            }
        }
    }
    else{
        FL(i,0,n){
            FL(j,1,n-i){
                if(a[j].start < a[j-1].start){
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                }
            }
        }
    }
}