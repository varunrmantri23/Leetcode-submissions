class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        return binarySearchHelper(nums, 0, size - 1);
    }

    int binarySearchHelper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return -1;  // No peak element found in the current subarray
        }
        
        int mid = start + (end - start) / 2;

        if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
            return mid;  // Found a peak element
        }
        else if (mid > 0 && nums[mid - 1] > nums[mid]) {
            // Recurse on the left subarray
            return binarySearchHelper(nums, start, mid - 1);
        }
        else {
            // Recurse on the right subarray
            return binarySearchHelper(nums, mid + 1, end);
        }
    }
};
