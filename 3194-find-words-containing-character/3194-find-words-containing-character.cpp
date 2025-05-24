class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        auto lambda  = [&x](char a){
            return a == x;
        };
        for(int i = 0; i < words.size();i++){
            if(any_of(words[i].begin(),words[i].end(),lambda) == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};