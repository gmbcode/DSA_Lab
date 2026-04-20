#include <stdio.h>
#include <stdlib.h>

#define FL(i,a,b) for(int i = a; i < b ; i++)
#define ll long long
#define MOD 1000000009

int n, m;
int base = 29;

// Renamed to avoid conflicts with math.h, and fixed the power of 0 bug
ll power(ll i, ll j) {
    if (j == 0) {
        return 1LL; 
    }
    ll result = 1;
    while (j > 0) {
        result = (result * i) % MOD;
        j--;
    }
    return result;
}

// Rewritten to match the rolling hash direction (highest power on the first char)
ll get_Hash_String(char* str, int l, int r) {
    ll roll_hsh = 0;
    FL(i, l, r + 1) {
        roll_hsh = (roll_hsh * base + (str[i] - 'a' + 1)) % MOD;
    }
    return roll_hsh;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    char t[n + 1];
    char p[m + 1];
    scanf("%s", t);
    scanf("%s", p);

    ll v = power(base, m - 1);

    // Fixed variable swap
    ll hash_p = get_Hash_String(p, 0, m - 1);
    ll hash_t = get_Hash_String(t, 0, m - 1);
    
    FL(i, 0, n - m + 1) {
        if (hash_p == hash_t) {
            int match = 1;
            FL(j, 0, m) {
                // Fixed the index offset checking logic
                if (t[i + j] != p[j]) { 
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("%d ", i);
            }
        }
        
        if (i < n - m) {
            // Remove leading digit, multiply by base, add trailing digit
            // Note: C handles modulo on negative numbers poorly, so we add MOD twice to be safe
            hash_t = (hash_t - ((t[i] - 'a' + 1) * v) % MOD) % MOD;
            
            if (hash_t < 0) {
                hash_t += MOD;
            }
            
            hash_t = (hash_t * base + (t[i + m] - 'a' + 1)) % MOD;
        }
    }
    
    printf("\n");
    return 0;
}