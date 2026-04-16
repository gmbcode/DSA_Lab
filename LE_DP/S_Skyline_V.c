#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Define a key point (x-coordinate and height)
typedef struct {
    int x;
    int h;
} Point;

// A dynamic array wrapper to hold a list of points
typedef struct {
    Point* pts;
    int count;
} Skyline;

// Function to create an empty skyline array of a certain capacity
Skyline* createSkyline(int capacity) {
    Skyline* s = (Skyline*)malloc(sizeof(Skyline));
    s->pts = (Point*)malloc(capacity * sizeof(Point));
    s->count = 0;
    return s;
}

// Function to add a point to a skyline, avoiding redundant consecutive heights
void appendPoint(Skyline* s, int x, int h) {
    if (s->count > 0 && s->pts[s->count - 1].h == h) {
        return; // Ignore if the height hasn't changed
    }
    if (s->count > 0 && s->pts[s->count - 1].x == x) {
        // If x is exactly the same, keep the maximum height
        s->pts[s->count - 1].h = MAX(s->pts[s->count - 1].h, h);
        return;
    }
    s->pts[s->count].x = x;
    s->pts[s->count].h = h;
    s->count++;
}

// The core Merge logic
Skyline* mergeSkylines(Skyline* s1, Skyline* s2) {
    Skyline* res = createSkyline(s1->count + s2->count);
    
    int h1 = 0, h2 = 0; // Current active heights of s1 and s2
    int i = 0, j = 0;   // Pointers for s1 and s2

    while (i < s1->count && j < s2->count) {
        int x, max_h;
        
        // Pick the point with the smaller x-coordinate
        if (s1->pts[i].x < s2->pts[j].x) {
            x = s1->pts[i].x;
            h1 = s1->pts[i].h; // Update active height for s1
            i++;
        } 
        else if (s1->pts[i].x > s2->pts[j].x) {
            x = s2->pts[j].x;
            h2 = s2->pts[j].h; // Update active height for s2
            j++;
        } 
        else {
            // Both points have the exact same x-coordinate
            x = s1->pts[i].x;
            h1 = s1->pts[i].h;
            h2 = s2->pts[j].h;
            i++;
            j++;
        }
        
        // The merged height is the max of the two active heights
        max_h = MAX(h1, h2);
        appendPoint(res, x, max_h);
    }

    // Append any remaining points from s1
    while (i < s1->count) {
        appendPoint(res, s1->pts[i].x, s1->pts[i].h);
        i++;
    }
    // Append any remaining points from s2
    while (j < s2->count) {
        appendPoint(res, s2->pts[j].x, s2->pts[j].h);
        j++;
    }

    // Free the old sub-skylines to prevent memory leaks
    free(s1->pts); free(s1);
    free(s2->pts); free(s2);

    return res;
}

// The Divide & Conquer function
Skyline* getSkyline(int buildings[][3], int left, int right) {
    // Base Case: 1 Building
    if (left == right) {
        Skyline* s = createSkyline(2);
        appendPoint(s, buildings[left][0], buildings[left][2]); // (left_x, height)
        appendPoint(s, buildings[left][1], 0);                  // (right_x, 0)
        return s;
    }

    int mid = left + (right - left) / 2;
    
    // Divide
    Skyline* left_skyline = getSkyline(buildings, left, mid);
    Skyline* right_skyline = getSkyline(buildings, mid + 1, right);
    
    // Conquer
    return mergeSkylines(left_skyline, right_skyline);
}

int main() {
    int n;
    scanf("%d", &n);

    int buildings[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &buildings[i][0], &buildings[i][1], &buildings[i][2]);
    }

    // Edge case: no buildings
    if (n == 0) return 0;

    Skyline* final_skyline = getSkyline(buildings, 0, n - 1);

    for (int i = 0; i < final_skyline->count; i++) {
        printf("(%d, %d) ", final_skyline->pts[i].x, final_skyline->pts[i].h);
    }
    printf("\n");

    free(final_skyline->pts);
    free(final_skyline);

    return 0;
}