#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_N 2000

typedef struct RList{
    ll arr[MAX_N];
    int count;
} RList;

ll tmp[MAX_N];
RList* memo[20][20];

void merge(ll* arr,ll* tmp,int l,int r){
    int mid = (l + r) / 2;
    int p1 = l;
    int p2 = mid + 1;
    int p3 = l;
    while(p1 <= mid && p2 <= r){
        if(arr[p1] > arr[p2]){
            tmp[p3++] = arr[p2++]; 
        }
        else{
            tmp[p3++] = arr[p1++];
        }
    }
    while(p1 <= mid){
        tmp[p3++] = arr[p1++];
    }
    while(p2 <= r){
        tmp[p3++] = arr[p2++];
    }
    p3 = l;
    while(p3 <= r){
        arr[p3] = tmp[p3];
        p3++;
    }
}

void mergeSort(ll* arr,ll* tmp,int l,int r){
    if(l >= r){
        return;
    }
    else{
        int mid = (l+r) / 2;
        mergeSort(arr,tmp,l,mid);
        mergeSort(arr,tmp,mid+1,r);
        merge(arr,tmp,l,r);
    }
}


RList* compute(char* s,int l,int r){
    if(memo[l][r] != NULL){
        return memo[l][r];
    }
    RList* rl = (RList*) malloc(sizeof(RList));
    rl -> count = 0;
    if(l == r){
        rl ->arr[rl -> count++] = s[l] - '0';
        return memo[r][l] = rl;
    }
    else{
        for(int i = l + 1; i <= r - 1 ; i += 2){
            char op = s[i];
            RList* lt = compute(s,l,i-1);
            RList* rt = compute(s,i+1,r);
            FL(u,0,lt->count){
                FL(v,0,rt -> count){
                    switch (op)
                    {
                    case '+':
                        rl -> arr[rl -> count++] = lt -> arr[u] + rt -> arr[v];
                        break;
                    case '-':
                        rl -> arr[rl -> count++] = lt -> arr[u] - rt -> arr[v];
                        break;
                    case '*':
                        rl -> arr[rl -> count++] = lt -> arr[u] * rt -> arr[v];
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        return memo[l][r] = rl;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    RList* ans = compute(s,0,n-1);
    mergeSort(ans -> arr,tmp,0,ans -> count - 1);
    FL(i,0,ans->count){
        printf("%d ",ans -> arr[i]);
    }
    printf("\n");
}