class Solution {
public:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int ans = 0;
        int n = arr.size();
        vector<int> pse(n);
        vector<int> nse(n);
        pse = findpse(arr);
        nse = findnse(arr);

        for (int i = 0; i < n; i++) {
            int prevIdx = pse[i];
            int nextIdx = nse[i];
            long long left = i - prevIdx;
            long long right = nextIdx - i;
            ans = (ans + (left * right) % mod * arr[i] % mod) % mod;
        }

        return ans;
    }
};
