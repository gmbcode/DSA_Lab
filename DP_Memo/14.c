#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MCON 3
/*
Question 14: Finding Closest Pair
Problem Description:
You are given two disjoint sets of points, P1 and P2, on a 2-dimensional Cartesian plane.
Determine the minimum Manhattan distance between any point p_i in P1 and any point p_j in
P2.
Manhattan Distance between (x1, y1), (x2, y2) -> |x1 - x2| + |y1 - y2|
The algorithm must strictly employ a Divide and Conquer methodology.
Expected Time Complexity: O((N + M) log(N + M))
Input Format:
Line 1: Two integers N, M (Number of points in P1 and P2, 1 ≤ N, M ≤ 5 * 10^4)
Next N Lines: Two integers x and y(coordinates of points in P1, -10^5 ≤ x, y ≤ 10^5)
Next M Lines: Two integers x and y(coordinates of points in P2, -10^5 ≤ x, y ≤ 10^5)
Output Format:
Minimum Manhattan distance between the points.*/
typedef struct Point{
    int x;
    int y;
    int type;
} Point;

int manhattan(Point a, Point b){
    if(a.type == b.type) return INT_MAX;
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void mrgCustomX(Point a[], Point tmp[], int l, int r){
    int mid = (l + r) / 2;
    int p1 = l, p2 = mid + 1, ptr = l;
    while (p1 <= mid && p2 <= r) {
        if(a[p1].x > a[p2].x) tmp[ptr++] = a[p2++];
        else tmp[ptr++] = a[p1++];
    }
    while(p1 <= mid) tmp[ptr++] = a[p1++];
    while(p2 <= r) tmp[ptr++] = a[p2++];
    FL(i,l,r+1) a[i] = tmp[i];
}

void mrgCustomY(Point a[], Point tmp[], int l, int r){
    int mid = (l + r) / 2;
    int p1 = l, p2 = mid + 1, ptr = l;
    while (p1 <= mid && p2 <= r) {
        if(a[p1].y > a[p2].y) tmp[ptr++] = a[p2++];
        else tmp[ptr++] = a[p1++];
    }
    while(p1 <= mid) tmp[ptr++] = a[p1++];
    while(p2 <= r) tmp[ptr++] = a[p2++];
    FL(i,l,r+1) a[i] = tmp[i];
}

void mrgSort(Point a[], Point tmp[], int l, int r, int mode){
    if(l >= r) return;
    int mid = (l + r) / 2;
    mrgSort(a, tmp, l, mid, mode);
    mrgSort(a, tmp, mid+1, r, mode);
    if(!mode) mrgCustomX(a, tmp, l, r);
    else mrgCustomY(a, tmp, l, r);
}

// Pass tmp_arr down so we don't rely on undeclared globals
int findClosest(Point* p, Point* tmp_arr, int left, int right){
    // FIX: Use 'left' to 'right' for base case
    if((right - left + 1) <= MCON){
        int min_d = INT_MAX;
        FL(u, left, right + 1){
            FL(v, u + 1, right + 1){ 
                if(p[u].type != p[v].type)
                    min_d = MIN(min_d, manhattan(p[u], p[v]));
            }
        }
        return min_d;
    }
    
    int mid = (left + right) / 2;
    int mid_x = p[mid].x; // Store mid_x before doing any sorting

    int lt = findClosest(p, tmp_arr, left, mid);
    int rt = findClosest(p, tmp_arr, mid+1, right);
    int d_best = MIN(lt, rt);

    int sz = right - left + 1;
    Point* strip = (Point*) malloc(sz * sizeof(Point));
    Point* strip_tmp = (Point*) malloc(sz * sizeof(Point));
    int strip_size = 0;
    
    // FIX: Iterate from 'left' to 'right + 1', not 0 to sz
    FL(i, left, right + 1){
        if(abs(p[i].x - mid_x) < d_best){
            strip[strip_size++] = p[i];
        }
    }
    
    if (strip_size > 1) {
        mrgSort(strip, strip_tmp, 0, strip_size - 1, 1);
        
        FL(i, 0, strip_size){
            for(int j = i + 1 ; j < strip_size && ((strip[j].y - strip[i].y) < d_best); j++){
                d_best = MIN(d_best, manhattan(strip[i], strip[j]));
            }
        }
    }
    
    free(strip);
    free(strip_tmp);
    return d_best;
}

int main(){
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    Point* pts = (Point*) malloc((n + m) * sizeof(Point));
    Point* tmp = (Point*) malloc((n + m) * sizeof(Point));
    
    int tmpx, tmpy;
    FL(i, 0, n){
        scanf("%d %d", &tmpx, &tmpy);
        pts[i].type = 1;
        pts[i].x = tmpx;
        pts[i].y = tmpy;
    }
    
    FL(i, n, n + m){
        scanf("%d %d", &tmpx, &tmpy);
        pts[i].type = 2;
        pts[i].x = tmpx;
        pts[i].y = tmpy;
    }
    
    mrgSort(pts, tmp, 0, n + m - 1, 0);
    
    int ans = findClosest(pts, tmp, 0, n + m - 1);
    printf("%d\n", ans);

    free(pts);
    free(tmp);
    
    return 0;
}