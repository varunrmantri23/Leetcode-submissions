class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int &num: nums){
            if((to_string(num)).size() % 2) continue;
            else ans++;
        }
        return ans;
    }
};