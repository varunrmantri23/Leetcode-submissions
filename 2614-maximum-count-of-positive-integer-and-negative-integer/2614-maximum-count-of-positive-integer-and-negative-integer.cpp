class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int poscounter = 0;
        int negcounter = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negcounter++;
            }
            else if(nums[i] > 0){
                poscounter++;
            }
            else continue;
        }

        return max(negcounter,poscounter);
        
    }
};