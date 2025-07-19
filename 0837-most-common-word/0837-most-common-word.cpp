class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        string ans = "";
        string currWord = "";
        for (int i = 0; i < paragraph.size(); i++) {
            if (paragraph[i] == '"' || paragraph[i] == '!' ||
                paragraph[i] == '?' || paragraph[i] == ',' ||
                paragraph[i] == ';' || paragraph[i] == '.') {
                if (!currWord.empty()) {
                    mp[currWord]++;
                    currWord = "";
                }
            } else if (isalpha(paragraph[i]))
                currWord += tolower(paragraph[i]);
            if (paragraph[i] == ' ') {
                if (!currWord.empty()) {
                    mp[currWord]++;
                    currWord = "";
                }
            }
        }
        if (!currWord.empty()) {
            mp[currWord]++;
        }
        unordered_set<string> ban(banned.begin(), banned.end());
        int maxCount = 0;
        for (auto it : mp) {
            cout << it.first << it.second << endl;
            if (ban.find(it.first) == ban.end()) {
                if (maxCount < it.second) {
                    ans = it.first;
                    maxCount = it.second;
                }
            }
        }
        return ans;
    }
};