
class Solution {
public:
    vector <vector<int>> cache;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        cache = vector<vector<int>>(n);
        vector<int> res = {};
        for(int k = 0; k < nums.size();k++){
            vector<int> temp = recursiveHelper(k, nums);
            if(temp.size() > res.size()) res = temp;
        }
        return res;
    }
    vector<int> recursiveHelper(int i, vector<int> &nums){
        // if(i == nums.size() - 1) return {};
        if(!cache[i].empty()) return cache[i];
        vector<int> res;
        for(int j = i+1; j < nums.size();j++){
            if(nums[j] % nums[i] == 0){
                vector<int> temp =recursiveHelper(j, nums);
                if(temp.size() > res.size()) res = temp;
            }
        }
        res.insert(res.begin(),nums[i]);
        cache[i] = res;
        return res;
    }
};



