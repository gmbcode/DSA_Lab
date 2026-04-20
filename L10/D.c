#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long


int M,R;

int h1(int k){
    return (k % M + M) % M;
}

int h2(int k){
    return R - (k % R);
}

int probe(int k,int i){
    return (h1(k) + i*h2(k)) % M;
}

void insertElement(int* arr,int key){
    int i = 0;
    int k = key;
    while(arr[probe(k,i)] != -1){
        i++;
    }
    arr[probe(k,i)] = key;
}
int main(){
    scanf("%d %d",&M,&R);
    int table[M];
    memset(table,-1,sizeof(table));
    int n;
    int tmp;
    scanf("%d",&n);
    FL(i,0,n){
        scanf("%d",&tmp);
        insertElement(table,tmp);
    }

    FL(i,0,M){
        printf("%d ",table[i]);
    }
    printf("\n");
}
