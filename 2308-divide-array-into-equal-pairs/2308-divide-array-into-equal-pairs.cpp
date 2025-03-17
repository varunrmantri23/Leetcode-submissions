class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //we can make a bitset and then flip bits if found, if we flip once we get false and .none() will return false if any bit is set so we get our ans.
        bitset<501> bs; //constraints given easy
        for(const int n:nums) bs.flip(n);
        return bs.none();
    }
};