#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long

int m,q;

int h(int k){
    return (k % m + m) % m;
}

void insertKey(int* table,int key){
    int idx = h(key);
    int count = 0; 
    while(table[idx] != -1 && count < m){
        if(table[idx] == -2){
            table[idx] = key;
            return;
        }
        idx = (idx + 1) % m;
        count++;
    }

    if(table[idx] == -1) {
        table[idx] = key;
    }
}

void deleteKey(int* table, int key){
    int idx = h(key);
    int count = 0;
    
    while(table[idx] != -1 && count < m){
        if(table[idx] == key){
            table[idx] = -2; 
            return;
        }
        idx = (idx + 1) % m;
        count++;
    }
}

void searchKey(int* table, int key){
    int idx = h(key);
    int count = 0;
    while(table[idx] != -1 && count < m){
        if(table[idx] == key){
            printf("Found\n");
            return;
        }
        idx = (idx + 1) % m;
        count++;
    }
    printf("Not Found\n");
}
int main(){
    scanf("%d %d",&m,&q);
    int* table = (int*) malloc(sizeof(int)*m);
    memset(table,-1,m * sizeof(int));
    int type;
    int val;
    FL(i,0,q){
        scanf("%d %d",&type,&val);
        if(type == 1){
            insertKey(table,val);
        }
        else if(type == 2){
            deleteKey(table,val);
        }
        else if(type == 3){
            searchKey(table,val);
        }
    }
    FL(i,0,m){
        printf("%d ",table[i]);
    }
    printf("\n");
}

