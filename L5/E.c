#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define ll long long

ll get_Div(ll n);
void bsort_div(ll n,ll a[],int mode);

int main(){
    ll n;
    scanf("%lld",&n);
    ll a[n];
    FL(i,0,n){
        scanf("%lld",&a[i]);
    }
    bsort_div(n,a,0);
    bsort_div(n,a,1);
    FL(i,0,n){
        printf("%lld ",a[i]);
    }
    printf("\n");
}

ll get_Div(ll n){
    if (n == 1) return 1;
    ll div = 2;
    ll index = 2;
    while(index*index <= n){
        if(n % index == 0){
            if(index*index == n){
                div++;
            }
            else{
                div += 2;
            }
        }
        index++;
    }
    return div;
}
void bsort_div(ll n,ll a[],int mode){
    ll tmp;
    if(!mode){
        FL(i,0,n){
            FL(j,1,n-i){
                if(get_Div(a[j]) < get_Div(a[j-1])){
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
                if((get_Div(a[j]) == get_Div(a[j-1])) && a[j] > a[j-1]){
                    tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                }
            }
        }    
    }
}


