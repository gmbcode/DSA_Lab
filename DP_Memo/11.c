#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
/*
Question 11: The Unstable Reactor (Ways to Add Parentheses)
Problem Description
A nuclear reactor’s pressure is computed using a mathematical expression consisting of
single-digit numbers and the binary operators + (addition), - (subtraction), and * (multiplication).
Due to a system failure, all parentheses in the expression were removed. Ignoring standard
operator precedence, your task is to determine all possible results that can be obtained by
inserting parentheses in different valid ways. To solve this efficiently, you are expected to use a
divide and conquer approach.
Note:
● Strictly Single Digits: Each number in the expression is a single digit (0–9). Multi-digit
numbers will not appear.
● No Unary Operators: The expression will not contain leading + or -. All operators are
strictly binary.
● Duplicates Allowed: If multiple parenthesizations yield the same result, all occurrences
must be included in the output.
● Sorting: Output all results in non-decreasing order, separated by spaces.
● The input expression is guaranteed to be valid.
● You must use 64-bit integers (long long in C) for all calculations.
*/
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX_N 5000
typedef struct {
    ll vals[MAX_N];
    int count;
} ResultList;

ll tmp[MAX_N];
ResultList* memo[20][20];


int merge(ll* arr,ll* tmp,int l,int r){
    int mid = (l + r) / 2;
    int p1 = l;
    int p2 = mid + 1;
    int p3 = l;
    while(p1 <= mid && p2 <= r){
        if(arr[p1] > arr[p2]){
            tmp[p3++] = arr[p2++];
        }
        else{
            tmp[p3++] = arr[p1++];
        }
    }
    while(p1 <= mid){
        tmp[p3++] = arr[p1++];
    }
    while(p2 <= r){
        tmp[p3++] = arr[p2++];
    }
    p3 = l;
    while(p3 <= r){
        arr[p3] = tmp[p3];
        p3++;
    }
}
void mergeSort(ll* arr,ll* tmp,int l,int r){
    if(l == r){
        return;
    }
    else{
        int mid = (l + r) / 2;
        mergeSort(arr,tmp,l,mid);
        mergeSort(arr,tmp,mid + 1,r);
        merge(arr,tmp,l,r);
    }

}
ResultList* compute(char* s, int left, int right){
    if(memo[left][right] != NULL){
        return memo[left][right];
    }
    ResultList* r = (ResultList*) malloc(sizeof(ResultList));
    r -> count = 0;
    if(left == right){
        r -> vals[r ->count++] = s[left] - '0'; // Convert to integer
        memo[left][right] = r;
        return r;
    }

    for(int i = left + 1 ; i <= right - 1; i += 2){
        char op = s[i];
        ResultList* leftres = compute(s,left,i-1);
        ResultList* rightres = compute(s,i+1,right);

        FL(u,0,leftres -> count){
            FL(v,0,rightres -> count){
                ll a = leftres->vals[u];
                ll b = rightres->vals[v];
                
                switch (op)
                {
                case '+':
                    r->vals[r->count++] = a + b;
                    break;
                case '-':
                    r->vals[r -> count++] = a - b;
                    break;
                case '*':
                    r->vals[r -> count++] = a * b;
                    break;
                default:
                    break;
                }
            }
        }
    }
    memo[left][right] = r;
    return r;
}
int main(){
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    ResultList* ans = compute(s,0,n-1);
    mergeSort(ans -> vals,tmp,0,ans -> count - 1);
    FL(i,0,ans -> count){
        printf("%lld ",ans -> vals[i]);
    }
}