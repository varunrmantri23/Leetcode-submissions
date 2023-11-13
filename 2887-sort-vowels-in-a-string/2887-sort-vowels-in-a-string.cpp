class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }

    string sortVowels(string s) {
        string temp;
        for (char c : s) {
            if (isVowel(c)) {
                temp += c;
            }
        }
        sort(temp.begin(), temp.end());

        int j = 0;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                ans += temp[j];
                j++;
            } else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};