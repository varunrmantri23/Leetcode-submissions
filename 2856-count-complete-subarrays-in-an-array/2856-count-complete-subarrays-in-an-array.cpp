class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> unique(nums.begin(), nums.end());
        int uniqueCount = unique.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                if (seen.size() == uniqueCount) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
