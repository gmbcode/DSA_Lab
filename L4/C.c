#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

struct Element{
    int index;
    int val;
};
//O(nlogn) based sorting
void msort(int left,int right,struct Element a[],struct Element temp[]);
void merge(int left,int right,struct Element a[],struct Element temp[]);

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    struct Element a[n];
    struct Element temp[n];
    FL(i,0,n){
        scanf("%d",&a[i].val);
        a[i].index = i;
    }
    msort(0,n-1,a,temp);
    int start = 0;
    int end = 1;
    while(start <= end && end < n && start < n){
        while(end < n && a[start].val == a[end].val){
            if(abs(a[start].index - a[end].index) > k){
                printf("%d %d \n",a[start].index,a[end].index);
                return 0;
            }
            end++;
        }
        start = end;
        end++;
    }
    printf("-1\n");
    

}

void merge(int left,int right,struct Element a[],struct Element temp[]){
    int mid = (left + right) / 2;
    int p1 = left;
    int p2 = mid + 1;
    int index = left;
    while(p1 <= mid && p2 <= right){
        if(a[p1].val <= a[p2].val){// Important condition for stable sorting
            temp[index++] = a[p1++];
        }
        else{
            temp[index++] = a[p2++];
        }
    }
    // Either of below two executed
    while(p1 <= mid){
        temp[index++] = a[p1++];
    }
    while(p2 <= right){
        temp[index++] = a[p2++];
    }
    index = left;
    while(index <= right){
        a[index] = temp[index];
        index++;
    }
}
void msort(int left,int right,struct Element a[],struct Element temp[]){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        msort(left,mid,a,temp);
        msort(mid + 1,right,a,temp);
        merge(left,right,a,temp);
    }
}
