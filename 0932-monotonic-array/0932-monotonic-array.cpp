class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = false;
        bool decreasing = false;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                increasing = true;
            } else if(nums[i] < nums[i - 1]) {
                decreasing = true;
            }
            
            // If both increasing and decreasing become true, it's not monotonic.
            if(increasing && decreasing) {
                return false;
            }
        }
        
        // If either increasing or decreasing is true, it's monotonic.
        return true;
    }
};
