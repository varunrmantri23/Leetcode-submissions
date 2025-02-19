class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> s; 
        helper(1, "a", 'a', n, s);
        helper(1, "b", 'b', n, s);
        helper(1, "c", 'c', n, s);

        sort(s.begin(), s.end());
        if (s.size() >= k) return s[k - 1]; 
        return "";
    }

    void helper(int len, string k, char a, int n, vector<string>& s) {
        if (len == n) {
            s.push_back(k);
            return;
        }
        if (a == 'a') {
            helper(len + 1, k + 'b', 'b', n, s);
            helper(len + 1, k + 'c', 'c', n, s);
        }
        if (a == 'b') {
            helper(len + 1, k + 'a', 'a', n, s);
            helper(len + 1, k + 'c', 'c', n, s);
        }
        if (a == 'c') {
            helper(len + 1, k + 'a', 'a', n, s);
            helper(len + 1, k + 'b', 'b', n, s);
        }
    }
};
