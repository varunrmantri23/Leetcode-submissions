class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> map(101,0);
        int n = nums.size(); 
        for(int i = n -1; i>= 0; i--){
            if(map[nums[i]] == 1){
                return (i + 1 + 2) / 3;
            }
            else map[nums[i]] = 1;
        }
        return 0;
    }
};


/*
dry run: 
    nums = [1,2,3,4,3,3,5,7]
    7,5,3 ,

*/