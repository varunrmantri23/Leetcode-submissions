class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n > 0 && n ==1) return true;
        if ( n == 2 || n == 3) return false;
        if(n > 3){
            if(n % 4 == 0){
                return isPowerOfFour(n/4);
            }
            else return false;
        }
        else return false;
    }
};