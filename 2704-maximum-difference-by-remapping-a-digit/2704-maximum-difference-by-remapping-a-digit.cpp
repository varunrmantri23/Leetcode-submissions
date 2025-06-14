class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        if (numStr.empty())
            return 0;
        char first = numStr[0];
        char firstMin = first;
        if(first == '9'){
            for(char a: numStr){
                if(a != '9'){
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
        for(int i = 0; i < numStr.length();i++){
            if(numStr[i] == firstMin){
                min[i] = '0';
            }
        }
        cout << max << endl;
        cout << min ;
        return stoi(max) - stoi(min);
    }
};