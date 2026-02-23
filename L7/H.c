#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

char q[200005][25];

int main(){
    int n;
    scanf("%d",&n);

    int front = 0;
    int rear = 0;
    
    strcpy(q[rear++], "1");

    FL(i,0,n){
        printf("%s ",q[front]);
        strcpy(q[rear],q[front]);
        strcat(q[rear],"0");
        rear++;
        strcpy(q[rear],q[front]);
        strcat(q[rear],"1");
        rear++;
        front++;
    }
    printf("\n");
}