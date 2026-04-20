#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *a = (int*) malloc(n * sizeof(int));
    FL(i, 0, n) {
        scanf("%d", &a[i]);
    }

    // Level 0 must be in sorted order
    qsort(a, n, sizeof(int), compare);

    // Find the top-most level H
    // H is the maximum level such that 2^H < N
    int H = 0;
    if (n > 1) {
        while ((1 << (H + 1)) < n) {
            H++;
        }
    }

    FL(i, 0, q) {
        int x;
        scanf("%d", &x);

        int curr = 0;
        int lvl = H;
        int steps = 0;
        int found = 0;

        // Fast fail: if X is outside the min/max bounds, it's not in the list
        if (n > 0 && x >= a[0] && x <= a[n - 1]) {
            while (1) {
                // Check if we are currently standing on the target
                if (a[curr] == x) {
                    found = 1;
                    break;
                }
                
                // Calculate the index if we moved right on the current level
                int next_idx = curr + (1 << lvl);
                
                if (next_idx < n && a[next_idx] <= x) {
                    // Move right
                    curr = next_idx;
                    steps++;
                } else {
                    // Cannot move right, must drop down
                    if (lvl == 0) break; // Already at bottom level, element doesn't exist
                    lvl--;
                    steps++;
                }
            }
        }

        if (found) {
            printf("%d ", steps);
        } else {
            printf("-1 ");
        }
    }
    
    printf("\n");
    free(a);
    return 0;
}