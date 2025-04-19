class Solution {
public:
    // #HashTag: #TwoPointers #LambdaFunction #RangeCount #OptimalAlgorithm
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort input array to enable efficient two-pointer solution
        // Time complexity: O(n log n)
        sort(nums.begin(), nums.end());
        
        // Lambda function for counting pairs with sum <= target
        // Captures references to nums by [&] for memory efficiency
        auto countPairsWithSumAtMost = [&](int target) -> long long {
            long long count = 0;  // Use long long to handle large arrays
            int left = 0;
            int right = nums.size() - 1;
            
            while (left < right) {
                int current_sum = nums[left] + nums[right];
                
                if (current_sum <= target) {
                    // Critical optimization: All elements between left+1 and right
                    // form valid pairs with nums[left], so add them all at once
                    count += right - left;
                    left++;  // Increment left to explore new pairs
                }
                else {
                    // Sum exceeds target, try smaller values by decreasing right
                    right--;
                }
            }
            return count;
        };
        
        // Calculate fair pairs using mathematical range calculation:
        // Count pairs in range [lower, upper] by computing the difference between
        // pairs with sum ≤ upper and pairs with sum ≤ (lower-1)
        return countPairsWithSumAtMost(upper) - countPairsWithSumAtMost(lower - 1);
    }
};