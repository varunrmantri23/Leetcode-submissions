class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numPairs;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            numPairs.push_back({nums[i], i});
        sort(numPairs.begin(), numPairs.end(),
             [](auto x, auto y) { return x.first > y.first; });
        numPairs.resize(k);
        sort(numPairs.begin(), numPairs.end(),
             [](auto x, auto y) { return x.second < y.second; });//second time sort w index to get og sequence
        nums = {};
        for (auto& [num, i] : numPairs)
            nums.push_back(num);
        return nums;
    }
};