class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p1 = 0;
        int n = nums.size();
        
        for (int p2 = 0; p2 < n; p2++) {
            if (p1 <= p2) {
                if (nums[p2] % 2 == 0 && nums[p1] % 2 != 0) {
                    // Swap elements without using extra memory
                    nums[p1] ^= nums[p2];
                    nums[p2] ^= nums[p1];
                    nums[p1] ^= nums[p2];
                    p1++;
                } else if (nums[p1] % 2 == 0) {
                    p1++;
                }
            }
        }
        
        return nums;
    }
};
