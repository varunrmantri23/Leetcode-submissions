class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //n^3
        long long answer = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j  = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    answer = max(answer, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return answer;
    }
};