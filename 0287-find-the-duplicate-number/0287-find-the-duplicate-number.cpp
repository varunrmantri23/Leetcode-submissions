class Solution {
public:
//by pigeonhole principle we can prove that atleast 1 repeated number exists
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>hashmap ;
        int n = nums.size();
        for(int i =0; i < n;i++){
            if(hashmap[nums[i]] == 1){
                return nums[i];
            }
            else {
                hashmap[nums[i]]++;
            }
        }
        return -1;
    }

};