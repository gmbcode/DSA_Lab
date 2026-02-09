#include<stdio.h>
#include<stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define FE(i,a,b) for(int i = a; i <= b ; i++)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define ll long long

// Rotate 1 D Array CW / CCW
void rotateArray(int *arr, int size, int direction) {
    if (size <= 1) return;

    if (direction == 1){ // Clockwise rt shift
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
    else{ // Counter Clockwise lft shift 
        int first = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size-1] = first;
    }
}

void processMatrix(int n, int m, int matrix[n][m]) {
    int layers = MIN(n,m) / 2;

    // Max perimeter is ~ 2*(N+M) -> temp arr for perimeter
    int *temp = (int *)malloc(2 * (n + m) * sizeof(int));

    FL(layer,0,layers){
        int r1 = layer;
        int r2 = n - 1 - layer;
        int c1 = layer;
        int c2 = m - 1 - layer;

        // Count elements in this layer
        int count = 0;

        // 1. Extract Elements (Top -> Right -> Bottom -> Left)
        
        // Top Row (Left to Right)
        for (int j = c1; j <= c2; j++) temp[count++] = matrix[r1][j];
        
        // Right Column (Top+1 to Bottom)
        for (int i = r1 + 1; i <= r2; i++) temp[count++] = matrix[i][c2];
        
        // Bottom Row (Right-1 to Left)
        for (int j = c2 - 1; j >= c1; j--) temp[count++] = matrix[r2][j];
        
        // Left Column (Bottom-1 to Top+1)
        for (int i = r2 - 1; i > r1; i--) temp[count++] = matrix[i][c1];

        int direction = (layer % 2 == 0) ? 1 : -1;
        if (r1 == r2 || c1 == c2) continue; // Skip rotation for single row/col
        rotateArray(temp, count, direction);

        count = 0;
        
        // Top Row
        for (int j = c1; j <= c2; j++) matrix[r1][j] = temp[count++];
        
        // Right Column
        for (int i = r1 + 1; i <= r2; i++) matrix[i][c2] = temp[count++];
        
        // Bottom Row
        for (int j = c2 - 1; j >= c1; j--) matrix[r2][j] = temp[count++];
        
        // Left Column
        for (int i = r2 - 1; i > r1; i--) matrix[i][c1] = temp[count++];
    }
    
    free(temp);
}

int main() {
    int n, m;
    scanf("%d %d",&n,&m);

    int matrix[n][m];
    FL(i,0,n){
        FL(j,0,m){
            scanf("%d", &matrix[i][j]);
        }
    }

    processMatrix(n, m, matrix);

    FL(i,0,n){
        FL(j,0,m){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}