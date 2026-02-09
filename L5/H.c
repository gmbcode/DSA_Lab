#include <stdio.h>
#include <stdlib.h>
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long


typedef struct {
    int start;
    int end;
} Interval;



void bsort(int n,Interval a[]);
int main() {
    int n;

    scanf("%d",&n);

    Interval intervals[n];
    FL(i,0,n){
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    bsort(n,intervals);

    int index = 0;
    FL(i,1,n){
        if(intervals[i].start <= intervals[index].end){
            intervals[index].end = MAX(intervals[index].end,intervals[i].end);
        }
        else{
            index++;
            intervals[index] = intervals[i];
        }
    }
    FE(i,0,index){
        printf("%d %d\n",intervals[i].start,intervals[i].end);
    }

}

void bsort(int n,Interval a[]){
    Interval tmp;
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