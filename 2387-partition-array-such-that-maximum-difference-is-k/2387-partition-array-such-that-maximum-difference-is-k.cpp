class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = nums[0];
        int ans = 1;
        for(int i = 1; i < nums.size();i++){
            if(nums[i] - diff > k){
                diff = nums[i];
                ans++;
            }
        }
        return ans;
    }
};