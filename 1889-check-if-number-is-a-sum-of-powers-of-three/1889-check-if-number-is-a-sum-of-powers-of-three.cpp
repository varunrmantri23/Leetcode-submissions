class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2 ) return false;

            n /= 3;
        }

        // The ternary representation of n consists only of 0s and 1s
        return true;
    }
};