class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char a : s) {
            freq[a - 'a']++;
        }
        int odd = 1, even = s.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] % 2 == 0) {
                    even = min(even, freq[i]);
                } else {
                    odd = max(odd, freq[i]);
                }
            }
        }

        return odd - even;
    }
};