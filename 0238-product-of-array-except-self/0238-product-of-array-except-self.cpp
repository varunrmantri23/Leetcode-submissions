class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            Input: nums = [1,2,4,6]
                    post_ans-right = [48,24,6,1]
                *   pre_ans-left  = [1,1,2,8]
            Output: [48,24,12,8]
             
         */
        int n = nums.size();
        vector<int> answer (n,1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix; 
            prefix *= nums[i];  
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] = postfix * answer[i]; 
            postfix *= nums[i];  
        }
        return answer;
    }
};
