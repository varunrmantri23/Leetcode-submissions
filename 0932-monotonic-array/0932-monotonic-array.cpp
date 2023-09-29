class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing = true; // Assume initially that it's increasing.
        bool decreasing = true; // Assume initially that it's decreasing.

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false; // If we find an increasing element, set decreasing to false.
            } else if (nums[i] < nums[i - 1]) {
                increasing = false; // If we find a decreasing element, set increasing to false.
            }

            // If neither increasing nor decreasing is true, it's not monotonic.
            if (!increasing && !decreasing) {
                return false;
            }
        }

        // If we reach here, either increasing is true or decreasing is true.
        return true;
    }
};
