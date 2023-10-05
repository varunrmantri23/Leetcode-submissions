class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementCountMap;
        
        for(int i = 0; i < nums.size(); i++) {
            elementCountMap[nums[i]]++;
        }
        
        vector<int> majorityElements;
        int threshold = nums.size() / 3;
        for(auto elementCountPair : elementCountMap) {
            int element = elementCountPair.first;
            int count = elementCountPair.second;
            
            // Check if the element count is greater than the threshold
            if(count > threshold) {
                majorityElements.push_back(element);
            }
        }
        
        return majorityElements;  
    }
};