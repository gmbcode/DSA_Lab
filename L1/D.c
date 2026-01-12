#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

void findUnion(int a[],int sz,int b[],int sz1);
void findIntersection(int a[],int sz,int b[],int sz1);
int main(){
    int m,n;
    scanf("%d",&m);
    int arr[m];
    FL(i,0,m){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&n);
    int arr1[n];
    FL(i,0,n){
        scanf("%d",&arr1[i]);
    }
    findUnion(arr,m,arr1,n);
    findIntersection(arr,m,arr1,n);  
}

void findUnion(int a[],int sz,int b[],int sz1){
    printf("Union: ");
    int found = 0;
    FL(i,0,sz){ // Print A- AintB
        found = 0;
        FL(j,0,sz1){
            if(a[i] == b[j]){
                found = 1;
            }
        }
        if(!found){
            printf("%d ",a[i]);
        }
    }
    FL(i,0,sz1){// Print B - AintB
        found = 0;
        FL(j,0,sz){
            if(b[i] == a[j]){
                found = 1;
            }
        }
        if(!found){
            printf("%d ",b[i]);
        }
    }
    FL(i,0,sz){ // Print A int B
        FL(j,0,sz1){
            if(a[i] == b[j]){
                printf("%d ",a[i]);
            }
        }
    }
    printf("\n");
}
void findIntersection(int a[],int sz,int b[],int sz1){
    printf("Intersection: ");
    FL(i,0,sz){
        FL(j,0,sz1){
            if(a[i] == b[j]){
                printf("%d ",a[i]);
            }
        }
    }
    printf("\n");
}
