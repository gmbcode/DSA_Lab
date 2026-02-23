#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

int main(){
    int sti[10000];
    int sto[10000];
    char out[10000];
    char* ptr = out;
    int r1 = 0;
    int r2 = 0;
    int t;
    int op;
    int num;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            scanf("%d",&num);
            sti[r1++] = num; // Enqueue into stack in
            break;
        case 2:
            if(r2 == 0){
                while(r1 != 0){
                    sto[r2++] = sti[--r1]; // Shift from stack in to stack out
                }
            }
            if(r2 == 0){
                ptr += sprintf(ptr,"-1\n");
            }
            else{
                ptr += sprintf(ptr,"%d\n",sto[--r2]);//Deque
            }
            break;
        case 3:
            if(r2 == 0){
                while(r1 != 0){
                    sto[r2++] = sti[--r1]; // Shift from stack in to stack out
                }
            }
            if(r2 == 0){
                ptr += sprintf(ptr,"-1\n");
            }
            else{
                ptr += sprintf(ptr,"%d\n",sto[r2 - 1]);//Peek
            }
            break;
        } 
    }
    printf("%s",out);
    
}