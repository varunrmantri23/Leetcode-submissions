class Solution {
public:
    long long coloredCells(int n) {
        long long result = (1 + (n * (long long)(n - 1) * 2));
        return result;
    }
};