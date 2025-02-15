class Solution {
public:
    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(to_string(square), i)) {
                totalSum += square;
            }
        }

        return totalSum;
    }

private:
    bool canPartition(const string& numStr, int target) {
        return backtrack(numStr, target, 0, 0);
    }

    bool backtrack(const string& numStr, int target, int start, int currentSum) {
        if (currentSum > target) return false;
        if (start == numStr.length()) return currentSum == target;

        for (int end = start + 1; end <= numStr.length(); end++) {
            // Get the substring and convert to integer
            string partStr = numStr.substr(start, end - start);
            int part = stoi(partStr);
            if (backtrack(numStr, target, end, currentSum + part)) {
                return true;
            }
        }
        return false;
    }
};
