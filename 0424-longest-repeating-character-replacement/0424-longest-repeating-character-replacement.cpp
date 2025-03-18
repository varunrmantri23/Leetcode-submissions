class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int answer = 0;
        int l = 0; 
        int max_freq = 0;  // maximum frequency of a single char in the current window
        
        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            // update the maximum frequency seen in the current window
            max_freq = max(max_freq, freq[s[r]]);
            
            // check if current window size minus the count of the most frequent
            // character is more than k. If so, shrink the window.
            while ((r - l + 1) - max_freq > k) {
                freq[s[l]]--;
                l++;
            }
            
            answer = max(answer, r - l + 1);
        }
        
        return answer;
    }
};
