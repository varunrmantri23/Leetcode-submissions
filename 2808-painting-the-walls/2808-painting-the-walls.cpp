class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            dp[n][i] = 1e9;
        }
        int opt1;
        int opt2;
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                opt1 = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];
                opt2 = dp[i + 1][remain];
                dp[i][remain] = min(opt1, opt2);
            }
        }
        
        return dp[0][n];
    }
};