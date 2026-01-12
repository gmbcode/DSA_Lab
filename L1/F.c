#include<stdio.h>
#include<string.h>
#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define FE(i,a,b) for(int i = a ; i <= b ; i++)

void bubblesort(int n,int a[]){
    int temp;
    FL(i,0,n){
        FL(j,1,n-i){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    FL(i,0,n){
        scanf("%d",&a[i]);
    }
    bubblesort(n,a);
    int index = 1;
    int prev = a[0];
    while (index < n)
    {
        int count = 1;
        //printf("index is (%d) prev is %d count is %d number is %d\n",index,prev,count,a[index]);
        if(a[index] == prev){
            count--;
        }
        while (a[index] == prev && index < n)
        {
            //printf("end index is (%d) prev is %d count is %d number is %d\n",index,prev,count,a[index]);
            count++;
            index++;
        }
        //printf("end index is (%d) prev is %d count is %d number is %d\n",index,prev,count,a[index]);
        printf("%d -> %d",prev,count);
        printf("\n");
        prev = a[index];
    }
    
}