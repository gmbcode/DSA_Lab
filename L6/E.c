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
    float stack[1001];
    int index = 0;
    int rear = 0;
    while(str[index] != '\0'){
        if(str[index] >= '0' && str[index] <= '9'){
            stack[rear++] = (float) (str[index] - '0');
        }
        else if(str[index] == '*' || str[index] == '/' || str[index] == '-' || str[index] == '+'){
            float res;
            if (rear < 2) {
                printf("Invalid Expression\n");
                return 0;
            }
            float v1 = stack[--rear];
            float v2 = stack[--rear];
            switch(str[index]){
                case '*':
                    res = v1 * v2;
                    break;
                case '+':
                    res = v1 + v2;
                    break;
                case '-':
                    res = v2 - v1;
                    break;
                case '/':
                    if(v1 == 0){
                        printf("Invalid expression\n");
                        return 0;
                    }
                    res = v2 / v1;
                    break;
            }
            stack[rear++] = res;
        }
        index++;
    }
    if(rear == 1){
        printf("%.2f\n",stack[0]);
    }
    else{
        printf("Invalid expression\n");
        return 0;
    }
}