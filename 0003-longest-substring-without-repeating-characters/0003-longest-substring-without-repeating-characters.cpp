class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int answer = 0;
        int curr_length  = 0;
        int l = 0, r = 0;
        while(r < s.length()){
            if(seen.count(s[r])){
                seen.erase(s[l]);
                curr_length--;
                l++;
            }
            else {
                curr_length ++;
                seen.insert(s[r]);
                answer = max(curr_length,answer);
                r++;
            }
        }

        return answer;

    }
};
