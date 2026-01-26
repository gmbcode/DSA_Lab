#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)
struct Student{
    int marks;
    int delay;
};

void bubblesort(int n,struct Student a[],int mode);
int main(){
    int n;
    scanf("%d",&n);
    struct Student arr[n];
    struct Student tmp;
    FL(i,0,n){
        scanf("%d %d",&tmp.marks,&tmp.delay);
        arr[i] = tmp;
    }
    bubblesort(n,arr,0);
    bubblesort(n,arr,1);
    FL(i,0,n){
        printf("%d %d\n",arr[i].marks,arr[i].delay);
    }
}

void bubblesort(int n,struct Student a[],int mode){
    struct Student tmp;
    if(!mode){
        FL(i,0,n){
            FL(j,1,n-i){
                if(a[j].marks > a[j-1].marks){
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                }
            }
        }
    }
    else{
        FL(i,0,n){
            FL(j,1,n-i){
                if(a[j].marks == a[j-1].marks && a[j].delay < a[j-1].delay){// Custom sorter for people w/ same marks
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                }
            }
        }
    }
}