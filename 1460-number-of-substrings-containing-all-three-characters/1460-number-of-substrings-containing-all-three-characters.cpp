class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int answer = 0;
        int left = 0; 
        int right = 0;
        int n = s.length();

        while(right < n){
            char ch = s[right];
            freq[ch - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                answer += (n - right);
                freq[s[left]-'a']--;
                left++;
            }
            right++;

        }
        return answer;
    }
};