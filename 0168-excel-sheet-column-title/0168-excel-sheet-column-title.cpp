class Solution {
public:
    string convertToTitle(int columnNumber) {
        string x ;
        char symbol;
        while(columnNumber){
            columnNumber--;
            x += (char)('A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        reverse(x.begin(),x.end());
        return x;
    }
};