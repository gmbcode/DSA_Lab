#include <stdio.h>
#include <stdlib.h>

#define FL(i, a, b) for(int i = a; i < b; i++)

// Structure to hold a single x, y coordinate
typedef struct {
    int x, y;
} Point;

// Structure to hold an array of points and its size
typedef struct {
    Point* pts;
    int sz;
} Skyline;

// The "Merge" step of Divide and Conquer
Skyline merge(Skyline s1, Skyline s2) {
    Skyline res;
    // Max possible points is the sum of both skylines
    res.pts = (Point*)malloc((s1.sz + s2.sz) * sizeof(Point));
    res.sz = 0;

    int i = 0, j = 0;
    int h1 = 0, h2 = 0;

    while (i < s1.sz && j < s2.sz) {
        int x;
        // Pick the smallest X coordinate
        if (s1.pts[i].x < s2.pts[j].x) {
            x = s1.pts[i].x;
            h1 = s1.pts[i].y;
            i++;
        } else if (s1.pts[i].x > s2.pts[j].x) {
            x = s2.pts[j].x;
            h2 = s2.pts[j].y;
            j++;
        } else {
            // If X coordinates are identical, process both simultaneously
            x = s1.pts[i].x;
            h1 = s1.pts[i].y;
            h2 = s2.pts[j].y;
            i++;
            j++;
        }

        // The current skyline height is the max of the two overlapping skylines
        int max_h = (h1 > h2) ? h1 : h2;

        // Only add the point if it's the first point OR the height has changed
        if (res.sz == 0 || res.pts[res.sz - 1].y != max_h) {
            res.pts[res.sz++] = (Point){x, max_h};
        }
    }

    // Add any remaining points from s1
    while (i < s1.sz) {
        if (res.sz == 0 || res.pts[res.sz - 1].y != s1.pts[i].y) {
            res.pts[res.sz++] = s1.pts[i];
        }
        i++;
    }

    // Add any remaining points from s2
    while (j < s2.sz) {
        if (res.sz == 0 || res.pts[res.sz - 1].y != s2.pts[j].y) {
            res.pts[res.sz++] = s2.pts[j];
        }
        j++;
    }

    // Free the old arrays to prevent memory leaks during recursion
    free(s1.pts);
    free(s2.pts);
    return res;
}

// The "Divide" step
Skyline getSkyline(int buildings[][3], int l, int r) {
    // Base Case: 1 Building left
    if (l == r) {
        Skyline res;
        res.pts = (Point*)malloc(2 * sizeof(Point));
        res.pts[0] = (Point){buildings[l][0], buildings[l][2]}; // [left, height]
        res.pts[1] = (Point){buildings[l][1], 0};               // [right, 0]
        res.sz = 2;
        return res;
    }

    int mid = l + (r - l) / 2;
    Skyline s1 = getSkyline(buildings, l, mid);
    Skyline s2 = getSkyline(buildings, mid + 1, r);
    
    return merge(s1, s2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Dynamically allocate the 2D array based on input N
    int (*buildings)[3] = malloc(n * sizeof(*buildings));
    
    FL(i, 0, n) {
        scanf("%d %d %d", &buildings[i][0], &buildings[i][1], &buildings[i][2]);
    }

    Skyline final_skyline = getSkyline(buildings, 0, n - 1);

    FL(i, 0, final_skyline.sz) {
        printf("%d %d\n", final_skyline.pts[i].x, final_skyline.pts[i].y);
    }

    free(final_skyline.pts);
    free(buildings);
    return 0;
}