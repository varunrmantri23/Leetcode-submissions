class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int count = 0;
        std::unordered_map<int, int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans[nums[i]]++;
        }

        for (const auto& it : ans) {
            int val = it.second;
            count = count + (val * (val - 1)) / 2;
        }
        return count;
    }
};