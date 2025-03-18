#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int answer = 0;
        int sum = 0; // using sum instead of a proper bitmask

        while (r < nums.size()) {
            // Attempt to check for a conflict using (sum & nums[r]).
            // With a true bitmask, (bitmask & nums[r]) != 0 means a conflict.
            // However, with 'sum' (an arithmetic sum), this does not hold.
            while (l < r && ((sum & nums[r]) != 0)) {
                sum -= nums[l];
                l++;
            }
            
            sum += nums[r];
            answer = max(answer, r - l + 1);
            r++;
        }
        
        return answer;
    }
};
