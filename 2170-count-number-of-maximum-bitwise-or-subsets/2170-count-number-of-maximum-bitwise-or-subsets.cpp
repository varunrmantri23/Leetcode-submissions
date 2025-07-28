class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        vector<vector<int>> dp(n+1, vector<int>(maxOR + 1, 0));
        // dp would look like nums on one side and the other will be maxor, the
        // final cell will hold our answer i.e dp[n-1][maxOR] which tells that
        // for maxOR we have these many subsets
        for (int j = 0; j <= maxOR; ++j) {
            dp[n][j] = (j == maxOR) ? 1 : 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < maxOR + 1; j++) {
                int countWithout = dp[i + 1][j];
                int orWith = (j | nums[i]);
                int countWith = 0;
                if (orWith <= maxOR) countWith = dp[i + 1][orWith];
                dp[i][j] = countWith + countWithout;
            }
        }
        return dp[0][0];
    }
};