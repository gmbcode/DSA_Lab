#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidSubstring(char* s, int start, int end, int k) {
    // Base Case 1: If the segment is shorter than K, it's impossible 
    if (end - start < k) {
        return 0;
    }

    // Step 1: Count frequencies of all characters in this specific segment
    int count[26] = {0};
    for (int i = start; i < end; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Scan for the first "toxic" character (frequency < k)
    for (int i = start; i < end; i++) {
        if (count[s[i] - 'a'] > 0 && count[s[i] - 'a'] < k) {
            
            // Step 3: We found a toxic character! Split the string here.
            // Calculate the longest valid substring in the LEFT piece
            int left_len = longestValidSubstring(s, start, i, k);

            // Optimization: Skip over any consecutive toxic characters
            // so we don't do useless empty recursions.
            while (i < end && count[s[i] - 'a'] < k) {
                i++;
            }

            // Calculate the longest valid substring in the RIGHT piece
            int right_len = longestValidSubstring(s, i, end, k);

            // Return the best of the two sides
            return MAX(left_len, right_len);
        }
    }

    // Step 4: If we make it through the whole loop without returning, 
    // it means NO toxic characters were found. The whole segment is valid!
    return end - start;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[n + 1];
    scanf("%s", s);

    // Call the recursive function on the entire string length
    int result = longestValidSubstring(s, 0, n, k);
    
    printf("%d\n", result);

    return 0;
}