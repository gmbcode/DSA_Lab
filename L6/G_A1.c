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
    int n;
    scanf("%d",&n);
    char str[1001];
    scanf("%s",str);
    char stack[10000];
    int top = -1;
    FL(i,0,n){
        if(str[i] != ']'){
            stack[++top] = str[i];
        }
        else{
            int pos = top;
            while(pos >= 0 && stack[pos] != '['){
                pos--;
            }
            // We have found the index of [
            int len = top - pos;
            char tmp[len + 1];
            FL(j,0,len){
                tmp[j] = stack[pos+j+1];
            }
            tmp[len] = '\0';

            int num_end = pos - 1;
            int num_start = num_end;
            while(num_start >= 0 && stack[num_start] >= '0' && stack[num_start] <= '9'){
                num_start--;
            }
            int k = 0;
            FL(i,num_start + 1,num_end + 1){
               k = k*10 + (stack[i] - '0') ;
            }

            top = num_start;
            FL(m,0,k){
                FL(j,0,len){
                    stack[++top] = tmp[j];
                }
            }


        }
    }
    stack[++top] = '\0';
    printf("%s\n", stack);
}