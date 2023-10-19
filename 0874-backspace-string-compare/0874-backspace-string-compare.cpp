class Solution {
public:
    bool backspaceCompare(string s, string t) {
    int i = s.size() - 1;
    int j = t.size() - 1;
    int sBackspace = 0;
    int tBackspace = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') {
                sBackspace++;
                i--;
            } else if (sBackspace > 0) {
                sBackspace--;
                i--;
            } else {
                break;
            }
        }

        while (j >= 0) {
            if (t[j] == '#') {
                tBackspace++;
                j--;
            } else if (tBackspace > 0) {
                tBackspace--;
                j--;
            } else {
                break;
            }
        }

        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}
};