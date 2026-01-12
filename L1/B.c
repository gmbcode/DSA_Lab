#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

void multiplymatrices(int r,int c,int a[][c],int r1,int c1,int a1[][c1]){
    int acc = 0;
    FL(i,0,r){
        FL(j,0,c1){
            acc = 0;
            FL(k,0,c){
                acc += a[i][k] * a1[k][j];
            }
            printf("%d ",acc);
        }
        printf("\n");
    }
}
int main(){
    int r,c;
    int r1,c1;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    FL(i,0,r){
        FL(j,0,c){
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d %d",&r1,&c1);
    int arr1[r1][c1];
    FL(i,0,r1){
        FL(j,0,c1){
            scanf("%d",&arr1[i][j]);
        }
    }
    if(c != r1){
        printf("Multiplication is not possible\n");
        return 0;
    }
    multiplymatrices(r,c,arr,r1,c1,arr1);


}