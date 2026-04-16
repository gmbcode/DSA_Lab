#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 1000000000 // A sufficiently large number for infinity
#define FL(i,a,b) for(int i = a ; i < b ; i++)
int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    
    int a[n];
    int prefix[n + 1];
    prefix[0] = 0; // Prefix sums to quickly calculate subarray sums
    
    FL(i,0,n){
        scanf("%d", &a[i]);
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    // 1. Feasibility Check
    if ((n - 1) % (k - 1) != 0) {
        printf("-1\n");
        return 0;
    }
    
    int dp[n][n];
    
    // Initialize DP table. 
    // Cost to merge segments smaller than K is naturally 0.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    
    // 2. Interval DP (Loop by length of subarray)
    for (int len = k; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            dp[i][j] = INF; 
            
            // 3. Try all valid splits
            // mid jumps by K-1 to ensure the left chunk can form exactly 1 pile
            for (int mid = i; mid < j; mid += (k - 1)) {
                dp[i][j] = MIN(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
            }
            
            // 4. Add the cost of the final merge if this segment can form 1 pile
            if ((j - i) % (k - 1) == 0) {
                // Cost is the sum of all stones in this segment
                dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
    }
    
    printf("%d\n", dp[0][n - 1]);
    
    return 0;
}