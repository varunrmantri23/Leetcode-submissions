#include <algorithm>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);

        // Handle the first two elements separately
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Calculate the minimum cost for the rest of the elements
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }

        // Return the minimum cost to reach the top
        return std::min(dp[n - 1], dp[n - 2]);
    }
};
