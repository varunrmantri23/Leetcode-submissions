class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //we can just make a hashset and insert values, if found pair then remove , finally return if hashset has any value left, if yes that means it was unpaired.
        unordered_set<int> hashset;
        for(int &a : nums){
            if(hashset.count(a)){
                hashset.erase(a);
            }
            else 
                hashset.insert(a);
        }
        return hashset.empty();
    }
};