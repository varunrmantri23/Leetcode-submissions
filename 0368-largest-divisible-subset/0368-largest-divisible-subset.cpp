class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // dp[i] stores the largest divisible subset starting at nums[i]
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]}; //each index will have itself nums[i] atleast
        }

        vector<int> res;

        for (int i = n - 1; i >= 0;i--) { //start from behind so its easy for front to just append
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    vector<int> temp = {nums[i]};
                    temp.insert(temp.end(), dp[j].begin(), dp[j].end()); //appending basically
                    if (temp.size() > dp[i].size()) {
                        dp[i] = temp;
                    }
                }
            }
            if (dp[i].size() > res.size()) { //at any point if dp[i] longer than res res = dp[i]
                res = dp[i];
            }
        }

        return res;
    }
};
