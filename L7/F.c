#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int main(){
    int queue[100000];
    int n,k;
    scanf("%d %d",&n,&k);
    int tickets[n];
    int time[n];

    FL(i,0,n){
        time[i] = 0;
        scanf("%d",&tickets[i]);
    }
    int front = 0;
    int rear = 0;
    FL(i,0,n){
        queue[rear++] = i;
    }
    int cur_time = 0;
    while (front != rear)
    {
        int cur = queue[front++];
        cur_time++;
        if(tickets[cur] > 1){
            tickets[cur]--;
            queue[rear++] = cur;
        }
        else{
            tickets[cur]--;
            time[cur] = cur_time;
        }
    }

    printf("%d\n",time[k]);

    
    

    

}