#include <stdio.h>
#include <string.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);
    
    char s[n+1];
    scanf("%s", s);
    
    // dp[i][j] stores the length of LPS in substring s[i...j]
    int dp[n][n];
    
    // Base case
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
        // Every single character is a palindrome of length 1
        dp[i][i] = 1; 
    }
    
    // Step 2: Build the table by increasing substring lengths
    // len is the length of the substring we are checking
    for (int len = 2; len <= n; len++) {
        // i is the starting index and j the ending index
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            // If the outer characters match
            if (s[i] == s[j]) {
                // If len == 2 nothing inside the outer characters therefore palindrome length is 2
                if (len == 2) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = 2 + dp[i+1][j-1]; // Add 2 to the inner palindrome
                }
            } 
            // If the outer characters do NOT match
            else {
                // Max of ignoring the left char OR ignoring the right char
                dp[i][j] = MAX(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    // The answer for the whole string from index 0 to n-1 is stored here
    printf("%d\n", dp[0][n-1]);
    
    return 0;
}