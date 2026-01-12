#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

struct Student{
    int id;
    char name[100];
    int m1,m2,m3;
};

int main(){
    int n;
    scanf("%d",&n);
    struct Student arr[n];
    char name[100];
    FL(i,0,n){
        scanf("%d",&arr[i].id); // Accept id
        scanf("%s",&arr[i].name); // Accept name
        scanf("%d",&arr[i].m1); // Accept m1
        scanf("%d",&arr[i].m2); // Accept m2
        scanf("%d",&arr[i].m3); // Accept m3
    }
    printf("Merit List :\n");
    int mav = 0;
    char topper[100];
    FL(i,0,n){
        float av = arr[i].m1 + arr[i].m2 + arr[i].m3;
        av /= 3.0;
        if(av > mav){
            mav = av;
            strcpy(topper,arr[i].name);
        }
        if(av > 75.0){
            printf("%d %s (Avg : %.2f)\n",arr[i].id,arr[i].name,av);
        }
    }
    printf("Topper : %s",topper);
}