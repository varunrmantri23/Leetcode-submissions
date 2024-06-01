class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 1;i < s.length();i++){
            sum = sum + abs(s[i] - s[i-1]);
        }
        return sum;
    }
};