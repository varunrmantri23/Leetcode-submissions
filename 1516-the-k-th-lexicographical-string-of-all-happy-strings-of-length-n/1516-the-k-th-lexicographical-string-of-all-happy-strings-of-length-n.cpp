class Solution {
public:
    vector<string> s; // Keeping s as a class member

    string getHappyString(int n, int k) {
       
        helper(1, "a", 'a', n);
        helper(1, "b", 'b', n);
        helper(1, "c", 'c', n);

        sort(s.begin(), s.end());
        if (s.size() >= k) return s[k - 1]; 
        return "";
    }

    void helper(int len, string k, char a, int n) {
        if (len == n) {
            s.push_back(k);
            return;
        }
        if (a == 'a') {
            helper(len + 1, k + 'b', 'b', n);
            helper(len + 1, k + 'c', 'c', n);
        }
        if (a == 'b') {
            helper(len + 1, k + 'a', 'a', n);
            helper(len + 1, k + 'c', 'c', n);
        }
        if (a == 'c') {
            helper(len + 1, k + 'a', 'a', n);
            helper(len + 1, k + 'b', 'b', n);
        }
    }
};
