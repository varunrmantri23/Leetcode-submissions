class Solution {
public:
    int differenceOfSums(int n, int m) {
        int j = n / m;
        return n * (n + 1) / 2 - j * (j + 1) * m;
    }
};