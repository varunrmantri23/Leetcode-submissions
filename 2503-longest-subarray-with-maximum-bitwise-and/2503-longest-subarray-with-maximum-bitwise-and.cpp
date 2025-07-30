class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAns = 0;
        maxAns = *max_element(nums.begin(),nums.end());
        int longestAnswer = 0;
        int curr = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == maxAns){
                curr++;
            }
            else {
                longestAnswer=max(curr,longestAnswer);
                curr = 0;
            }
        }
        longestAnswer=max(curr,longestAnswer);
        return longestAnswer;
    }
};