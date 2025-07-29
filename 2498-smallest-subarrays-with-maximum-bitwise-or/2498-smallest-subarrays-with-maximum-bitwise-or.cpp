class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        //for every nums[i] we want to find next index to or and get all set bits
        vector<int> results(nums.size());
        vector<int> setBitIndex(32,-1);
        
        for(int i = nums.size()-1; i >= 0;i--){
            int endIndex = i;
            for(int j = 0; j < 32;j++){
                if(!(nums[i] & (1<<j))){
                    if(setBitIndex[j] != -1){
                        endIndex = max(endIndex, setBitIndex[j]);
                    }
                }
                else setBitIndex[j] = i;
            }
            results[i] = endIndex - i + 1;
        }
        return results;
    }
};