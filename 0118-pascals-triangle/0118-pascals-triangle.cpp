class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1){
            return ans;
        }
        vector<int> prev = ans[0];
        for(int i = 1; i < numRows;i++){
            vector<int> curr;
            curr.push_back(prev[0]);
            for(int i = 0; i < prev.size()-1;i++){
                curr.push_back(prev[i]+prev[i+1]);
            }
            curr.push_back(prev[prev.size()-1]);
            ans.push_back(curr);
            prev = curr;
        }
        return ans;
    }
};