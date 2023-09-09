class Solution {
public:
    static const int MAX = 1010;
    int dp[MAX];
    int combinationSum4(vector<int>& nums, int target) {
        for(int j = 0; j < MAX ; j++){
            dp[j] = -1;
        }
        return combinationhelper(nums,target);
    }

    int combinationhelper(vector<int> &nums, int remainingtarget){
        if(remainingtarget == 0){
            return 1;
        }
        if(remainingtarget < 0){
            return 0;
        }
        if(~dp[remainingtarget]){
            return dp[remainingtarget];
        }

        int currentcombinations = 0;

        for(int i = 0; i < nums.size();i++){
            int currentnum = nums[i];
             
            currentcombinations += combinationhelper(nums, remainingtarget - currentnum);
        }
        dp[remainingtarget] =  currentcombinations;
        return  dp[remainingtarget];
    }

};