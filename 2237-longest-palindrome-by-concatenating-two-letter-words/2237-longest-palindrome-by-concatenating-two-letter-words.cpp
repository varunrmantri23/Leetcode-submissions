class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mp;
        for(int i = 0;i < words.size();i++){
            string rev  = string() + words[i][1] + words[i][0];
            if(mp[rev] != 0){
                ans+= 4;
                mp[rev]--;
            }
            else mp[words[i]]++;
        }
        bool f = false;
        for(auto i : mp){
            if(i.first[0] == i.first[1]){
                if(i.second % 2 == 1) f = true;
                ans += (i.second / 2) * 4;
            }
        }
        if(f) ans += 2;
        return ans;
    }
};