class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        generateSubsets(nums, 0, {}, subsets);

        int result = 0;
        for (auto& subset : subsets) {
            int subsetXORTotal = 0;
            for (int num : subset) {
                subsetXORTotal ^= num;
            }
            result += subsetXORTotal;
        }
        return result;
    }
    
    void generateSubsets(const vector<int>& nums, int index, vector<int> subset, vector<vector<int>>& subsets) {
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.pop_back();

        generateSubsets(nums, index + 1, subset, subsets);
    }
};