class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if n is a positive power of 2
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }
        
        // Check if the only set bit is at an even position
        return (n & 0x55555555) != 0;
    }
};
