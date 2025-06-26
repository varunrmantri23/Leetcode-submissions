class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0;
        int value = 0;
        int power = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[n - i - 1] == '0') {
                cnt++; // zero always works
            } else {
                if (i < 32 - __builtin_clz(k) && (value + (1 << i)) <= k) {
                    value += (1 << i);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
