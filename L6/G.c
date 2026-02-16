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
    int rear = 0;
    int top;
    FL(i,0,n){
        if(str[i] != ']'){
            stack[rear++] = str[i];
        }
        else{
            int pos = rear - 1;
            top = rear - 1;
            while(pos >= 0 && stack[pos] != '['){
                pos--;
            }
            int len = top - pos;
            char tmp[len+1];
            FL(j,0,len){
                tmp[j] = stack[pos + j + 1];
            }//Extract segment into temp array
            tmp[len] = '\0';
            
            int num_e = pos - 1;
            int num_s = num_e;
            while(num_s >= 0 && stack[num_s] >= '0' && stack[num_s] <= '9'){
                num_s--;
            }

            num_s++;

            int k = 0;
            int start = num_s;
            while(start <= num_e){
                k = k * 10 + (stack[start++] - '0');
            }
            int ind = num_s;
            FL(u,0,k){
                FL(j,0,len){
                    stack[ind++] = tmp[j];
                }
            }
            rear = ind;
        }
    }
    stack[rear++] = '\0';
    printf("%s\n", stack);
}