#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

int main(){
    char str[1000];
    fgets(str,1000,stdin); //Accept input
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    int start = 0;
    int end = 0;
    int ct = 0;
    char sc;
    while(end < count && start < count){
        sc = str[start];
        ct = 0;
        while(str[end] == sc && end < count){
            end++;
            ct++;
        }
        if(end > count){
            end--;
        }
        printf("%c%d",sc,ct);
        start = end;
        if(end == start && start == count-1){
            break;
        }
    }
}