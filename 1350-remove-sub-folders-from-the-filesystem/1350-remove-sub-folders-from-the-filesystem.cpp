class Solution {
private:
    bool includePattern(string &prev, string&curr){
        if(curr.size() == 1){
            // only '/'
            return false;
        }
        if(prev.size() > curr.size()){
            return false;
            //if prev was /a/b/c , curr is a/b/ so it is still present 
        }
        return curr.substr(0, prev.size()) == prev && curr[prev.size()] == '/';
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        string uniquePrev = folder[0];
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for(int i = 1; i < n;i++){
            //we check if curr string has previous string matching as it is from start then subfolders inside are already deleted
            // cout << folder[i] <<endl;
            // if(uniquePrev.size()  > 1 && folder[i].size() > 1 && uniquePrev[1] != folder[i][1]){
            //     uniquePrev =  folder[i];
            //     ans.push_back(folder[i]);
            //     continue;
            // }
            if(!includePattern(ans.back(), folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};