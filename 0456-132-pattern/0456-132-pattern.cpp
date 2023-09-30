class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n = nums.size();
       vector<int> newarr(n, 0);
       newarr[0] = nums[0];
       for (int i = 1; i < n; i++) {
           newarr[i] = min(newarr[i-1], nums[i]);
       }
       stack<int> stack;
       for (int j = n-1; j >= 0; j--) { 
           if (nums[j] > newarr[j]) {
               while (!stack.empty() && stack.top() <= newarr[j]) 
                    stack.pop();
               if (!stack.empty() && stack.top() < nums[j]) 
                        return true;
               stack.push(nums[j]);
           }
       }
       return false;
    }
};
