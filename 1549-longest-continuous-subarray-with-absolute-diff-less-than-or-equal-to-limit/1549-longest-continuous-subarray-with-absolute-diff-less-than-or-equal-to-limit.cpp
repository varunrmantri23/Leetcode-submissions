class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int i = 0, maxLength = 0;
        for(int j=0;j < nums.size();j++){
            window.insert(nums[j]);
            while(*window.rbegin() - *window.begin() > limit){
                window.erase(window.find(nums[i]));
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};