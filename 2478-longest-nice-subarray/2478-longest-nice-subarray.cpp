class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int answer = 0;
        int bitmask = 0; // stores the bitwise OR of the current subarray
        
        // two-pointer approach
        while (r < nums.size()) {
            // if conflict (common bits found), shrink window from left
            while ((bitmask & nums[r]) != 0) {
                bitmask ^= nums[l]; // remove nums[l] from bitmask
                l++;
            }
            
            bitmask |= nums[r]; // add nums[r] to bitmask
            answer = max(answer, r - l + 1); // update answer
            r++; // expand right pointer
        }
        
        return answer;
    }
};
