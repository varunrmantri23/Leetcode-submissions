class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        int count = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int num : nums) {
            if (num % modulo == k)
                count = (count + 1) % modulo;

            int needed = (count - k + modulo) % modulo;
            res += freq[needed];
            freq[count]++;
        }

        return res;
    }
};