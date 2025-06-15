class Solution {
public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        if (numStr.empty())
            return 0;
        char first = numStr[0];
        char x = 0;
        char firstMin = first;
        for (char a : numStr) {
            if (a >'1') {
                x = a;
                break;
            }
        }
        if (first == '9') {
            for (char a : numStr) {
                if (a != '9') {
                    first = a;
                    break;
                }
            }
        }
        string max = numStr, min = numStr;
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] == first) {
                max[i] = '9';
            }
        }
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] == x) {
                if (numStr[0] == x)
                    min[i] = '1';
                else
                    min[i] = '0';
            }
        }
        // cout << max << " " << min << endl;
        return stoi(max) - stoi(min);
    }
};