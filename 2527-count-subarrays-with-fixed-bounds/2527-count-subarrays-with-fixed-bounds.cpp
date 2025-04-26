class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalCount = 0; 
        int lastInvalidIndex = -1, lastMinKIndex = -1, lastMaxKIndex = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalidIndex = i;
            if (nums[i] == minK)
                lastMinKIndex = i;
            if (nums[i] == maxK)
                lastMaxKIndex = i;

            int validStart = min(lastMinKIndex, lastMaxKIndex);
            totalCount += max(0, validStart - lastInvalidIndex);
        }

        return totalCount;
    }
};