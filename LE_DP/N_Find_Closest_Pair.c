#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct Point{
    int x;
    int y;
    int type;
}Point;

Point TMP[10000];

void mrgSort(Point a[],Point tmp[],int l,int r,int mode){
    if(!mode){
        if(l >= r){
            return;
        }
        else{
            int mid = (l + r) / 2;
            mrgSort(a,tmp,l,mid,mode);
            mrgSort(a,tmp,mid+1,r,mode);
            mrgCustomX(a,tmp,l,r);
        }
    }
    else{
        if(l >= r){
            return;
        }
        else{
            int mid = (l + r) / 2;
            mrgSort(a,tmp,l,mid,mode);
            mrgSort(a,tmp,mid+1,r,mode);
            mrgCustomY(a,tmp,l,r);
        }
    }

}

void mrgCustomX(Point a[],Point tmp[],int l,int r){
    int mid = (l + r) / 2;
    int p1 = l;
    int p2 = mid + 1;
    int ptr = l;
    while (p1 <= mid && p2 <= r)
    {
        if(a[p1].x > a[p2].x){
            tmp[ptr++] = a[p2++];
        }
        else{
            tmp[ptr++] = a[p1++];
        }
    }
    while(p1 <= mid){
        tmp[ptr++] = a[p1++];
    }
    while(p2 <= r){
        tmp[ptr++] = a[p2++];
    }
    
    ptr = l;
    FL(i,l,r+1){
        a[i] = tmp[i];
    }
    return; 
}

void mrgCustomY(Point a[],Point tmp[],int l,int r){
    int mid = (l + r) / 2;
    int p1 = l;
    int p2 = mid + 1;
    int ptr = l;
    while (p1 <= mid && p2 <= r)
    {
        if(a[p1].y > a[p2].y){
            tmp[ptr++] = a[p2++];
        }
        else{
            tmp[ptr++] = a[p1++];
        }
    }
    while(p1 <= mid){
        tmp[ptr++] = a[p1++];
    }
    while(p2 <= r){
        tmp[ptr++] = a[p2++];
    }
    
    ptr = l;
    FL(i,l,r+1){
        a[i] = tmp[i];
    }
    return; 
}

int manhattan(Point p1, Point p2) {
    if (p1.type == p2.type) return INT_MAX; // Strictly bipartite restriction
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int closest_pair(Point* p,int n){
    if(n <= 3){
        int mind = INT_MAX;
        FL(i,0,n){
            FL(j,i+1,n){
                mind = MIN(mind,manhattan(p[i],p[j]));
            }
        }
        return mind;
    }
    int mid = n / 2;
    Point midpt = p[mid];
    int dl = closestPair(p, mid);
    int dr = closestPair(p + mid, n - mid);
    int d = MIN(dl, dr);
    Point* strip = (Point*) malloc(n*sizeof(Point));
    int strip_size = 0;
    FL(i,0,n){
        if(abs(p[i].x - midpt.x) < d){
            strip[strip_size++] = p[i];
        }
    }
    mrgSort(strip,TMP,0,strip_size-1,1);
    FL(i,0,strip_size){
        for (int j = i + 1; j < strip_size && (strip[j].y - strip[i].y) < d; j++) {
            d = MIN(d, manhattan(strip[i], strip[j]));
        }
    }
    free(strip);
    return d;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Point pts[n+m];
    int tmpx;
    int tmpy;
    FL(i,0,n){
        Point p;
        scanf("%d",&tmpx);
        scanf("%d",&tmpy);
        p.type = 1;
        p.x = tmpx;
        p.y = tmpy;
        pts[i] = p;
    }
    FL(i,n,m){
        Point p;
        scanf("%d",&tmpx);
        scanf("%d",&tmpy);
        p.type = 2;
        p.x = tmpx;
        p.y = tmpy;
        pts[i] = p;
    }
    Point tmp[n+m];
    mrgSort(pts,tmp,0,n-1,0);
    int ans = closest_pair(pts,n+m);
    printf("%d\n", ans);

    free(pts);

}