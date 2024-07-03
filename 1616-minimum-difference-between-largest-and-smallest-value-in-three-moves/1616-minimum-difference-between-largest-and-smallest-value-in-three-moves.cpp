class Solution {
public:
    void shift(vector<int>& a, int start) {
        int last = a.back();
        for(int j = a.size() - 1; j > start; j--) {
            a[j] = a[j - 1];
        }
        if(a.size() < 4) a.push_back(last);
    }
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) {
            return 0;
        }
        
        vector<int> min4, max4;
        
        for(int i = 0; i < nums.size(); i++) {
            bool add = false;
            for(int j = 0; j < min4.size(); j++) {
               if(nums[i] < min4[j]) {
                   shift(min4, j);
                   min4[j] = nums[i];
                   add = true;
                   break;
               }
            } 
            if(!add && min4.size() < 4) {
                min4.push_back(nums[i]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            bool add = false;
            for(int j = 0; j < max4.size(); j++) {
               if(nums[i] > max4[j]) {
                   shift(max4, j);
                   max4[j] = nums[i];
                   add = true;
                   break;
               }
            } 
            if(!add && max4.size() < 4) {
                max4.push_back(nums[i]);
            }
        }
        
        int ans = max4[0] - min4[0];
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, max4[3 - i] - min4[i]);
        }
        return ans;
    }
    
    
};