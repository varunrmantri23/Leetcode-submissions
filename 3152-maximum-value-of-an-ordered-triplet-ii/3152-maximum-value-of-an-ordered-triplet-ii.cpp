class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //optimal approach - greedy
        //just focus on maximising the diffeence of i and j, and we can fix all k and check 
        int n = nums.size();
        long long answer = 0, imax = 0, dmax = 0;
        for(int k = 0; k < n; k++){
            answer = max(answer, (long long)dmax * nums[k]);
            dmax = max(dmax, (long long)imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }
        return answer;
    }
};