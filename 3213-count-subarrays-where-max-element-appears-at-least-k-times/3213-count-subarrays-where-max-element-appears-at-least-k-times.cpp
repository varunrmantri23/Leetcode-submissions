class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxElement = *max_element(nums.begin(), nums.end());
        int x = count(nums.begin(), nums.end(), maxElement);
        if (x < k)
            return 0;
        long long ans = 0;
        unordered_map<int, int> freq;
        int j = 0;
        int countMax = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxElement)
                countMax++;

            while (countMax >= k) {
                ans += (n - i);
                if (nums[j] == maxElement)
                    countMax--;
                j++;
            }
        }

        return ans;
    }
};