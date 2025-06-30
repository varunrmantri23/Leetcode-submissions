class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int l = 0, r = 0;
        while(r < nums.size()){
            int x = nums[r];
            while(l < r && nums[l] < x - 1) l++;
            if(nums[l] == x-1 ) res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};