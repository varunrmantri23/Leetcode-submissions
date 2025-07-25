class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> freq(101,0);
        bool allNegative = nums[0] < 0 ? true:false;
        for(int num: nums){
            if(num >= 0){
                freq[num] = 1;
                allNegative = false;
            }
        }
        int ans = 0;
        if(allNegative) return *max_element(nums.begin(),nums.end());
        else {
            for(int i = 0; i < 101;i++){
                ans += freq[i] == 1 ? i : 0;
            }
        }
        return ans;
    }
};