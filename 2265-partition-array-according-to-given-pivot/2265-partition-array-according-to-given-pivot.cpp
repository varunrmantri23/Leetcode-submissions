class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < pivot) {
                for (int k = j - 1; k >= i; k--) {
                    swap(nums[k], nums[k + 1]);
                }
                i++;
            }
        }
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == pivot) {
                for (int k = j - 1; k >= i; k--) {
                    swap(nums[k], nums[k + 1]);
                }
                i++;
            }
        }
        return nums;
    }
};