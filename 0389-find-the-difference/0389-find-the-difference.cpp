class Solution {
public:
        char findTheDifference(string s, string t) {
        char ret ='\0';
        for (auto &c: s) ret^=c;
        for (auto &c: t) ret^=c;
        return ret;
    }
};