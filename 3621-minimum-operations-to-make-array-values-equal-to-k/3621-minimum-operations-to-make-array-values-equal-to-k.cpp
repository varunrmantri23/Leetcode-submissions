class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> freq(101,0);
        for(int num :nums){
            if(num < k) return -1;
            freq[num]++;
        }   
        int ans = 0;
        for(int j = freq.size() - 1; j>= k+1; j--){
            if(freq[j] > 0) ans++;
        }
        return ans;
    }
};