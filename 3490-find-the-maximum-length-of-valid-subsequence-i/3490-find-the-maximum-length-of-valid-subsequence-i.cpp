class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o = 0;
        int e = 0;
        int res = 1;
        int parity = nums[0] % 2;
        for (int i = 0; i < nums.size(); i++) {
            if (parity % 2 != nums[i] % 2) {
                res++;
                parity ^= 1;
            }
            if (nums[i] % 2) o++;
            else e++;
        }
        return max(o, max(e, res));
    }
};