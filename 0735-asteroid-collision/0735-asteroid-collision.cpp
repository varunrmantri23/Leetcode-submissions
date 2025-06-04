class Solution {
   public:
    void poptillvalid(stack<int> &st, int asteroid) {
        while (!st.empty() && st.top() > 0 && asteroid < 0) {
            if (abs(asteroid) == abs(st.top())) {
                st.pop();
                return;
            } else if (abs(st.top()) < abs(asteroid)) {
                st.pop();
            } else
                return;
        }
        st.push(asteroid);
            return;
    }
    bool issame(int x, int y) { return (x > 0 && y > 0) || (y < 0 && x < 0); }
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> st;
        for (int asteroid : asteroids) {
            if (!st.empty() && !issame(asteroid, st.top())) {
                poptillvalid(st, asteroid);
            } else
                st.push(asteroid);
        }
        vector<int> ans;
        int size = st.size();
        for (int i = 0; i < size; i++) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};