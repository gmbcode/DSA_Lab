#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long
#define I_MAX INT_MAX
#define I_MIN INT_MIN

int main(){
    char str[1000];
    fgets(str,1000,stdin);
    int stack[1001];
    
    int index = 0;
    int rear = 0;
    int mx = 0;
    stack[rear++] = -1; // Important
    while(str[index] != '\0'){
        if(str[index] == '('){
            stack[rear++] = index;
        }
        if(str[index] == ')'){
            rear--;
            if(rear == 0){
                stack[rear++] = index; // Stack is empty ie we have an invalid sequence so reset the index
            }
            else{
                mx = MAX(mx, index - stack[rear - 1]);
            }
        }
        index++;
    }
    printf("%d\n",mx);

}