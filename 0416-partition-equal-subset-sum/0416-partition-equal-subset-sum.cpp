class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum  = 0;
        for(auto &num :nums){
            sum += num;
        }
        if(sum % 2 == 1) return false; //if sum -> odd then return false as we cant divide in two with equal sum 
        
        int targetSum = sum / 2;
        vector<bool> dp(targetSum + 1, false);

        dp[0] = true;
        for(int num: nums){
            for(int curr = targetSum; curr >= num; curr--){
                dp[curr] = dp[curr] || dp[curr - num];
                if(dp[targetSum]) return true;
            }
        }
        return dp[targetSum];
    }
};