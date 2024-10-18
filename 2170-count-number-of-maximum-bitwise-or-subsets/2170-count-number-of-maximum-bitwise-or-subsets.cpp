class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOrValue = 0;

        // Calculate the maximum OR value
        for (int num : nums) {
            maxOrValue |= num;
        }

        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));

        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
    }

private:
    int countSubsetsRecursive(vector<int>& nums, int index, int currentOr,
                              int targetOr, vector<vector<int>>& memo) {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Check if the result for this state is already memoized
        if (memo[index][currentOr] != -1) {
            return memo[index][currentOr];
        }

        // Don't include the current number
        int countWithout =
            countSubsetsRecursive(nums, index + 1, currentOr, targetOr, memo);

        // Include the current number
        int countWith = countSubsetsRecursive(
            nums, index + 1, currentOr | nums[index], targetOr, memo);

        // Memoize and return the result
        return memo[index][currentOr] = countWithout + countWith;
    }
};