class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long minsum = LLONG_MAX;
        long long count = 0;
        long long ideal = 0;
        for(int n : nums){
            int x = n ^ k;
            ideal += max(n, x);
            if(x > n) {
                count++;
                minsum = min(minsum, static_cast<long long>(x - n));
            } else {
                minsum = min(minsum, static_cast<long long>(n - x));
            }
        }
        if(count%2 == 1){
            ideal -= minsum;
        }
        return ideal;
    }
};