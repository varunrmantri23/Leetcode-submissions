class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for (int j = 1; j < n; j++) {
            long long a_next = e;
            long long e_next = (a + i) % MOD;
            long long i_next = (a + e + o + u) % MOD;
            long long o_next = (i + u) % MOD;
            long long u_next = a;
            
            a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;
        }
        
        return (a + e + i + o + u) % MOD;
    }
};