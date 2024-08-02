class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int op1 = minSwapsHelper(nums, 0);
        int op2 = minSwapsHelper(nums, 1);
        return min(op1, op2);
    }

private:
    int minSwapsHelper(const vector<int>& data, int val) {
        int length = data.size();
        vector<int> rightSuffixSum(length + 1, 0);
        for (int i = length - 1; i >= 0; i--) {
            rightSuffixSum[i] = rightSuffixSum[i + 1];
            if (data[i] == (val ^ 1)) rightSuffixSum[i]++;
        }
        int totalSwapsNeeded = rightSuffixSum[0];
        int currentSwapCount = 0;
        int minimumSwaps =
            totalSwapsNeeded - rightSuffixSum[length - totalSwapsNeeded];
        for (int i = 0; i < totalSwapsNeeded; i++) {
            if (data[i] == (val ^ 1)) currentSwapCount++;
            int remaining = (totalSwapsNeeded - i - 1);
            int requiredSwaps =
                ((i + 1) - currentSwapCount) +
                (remaining - rightSuffixSum[length - remaining]);
            minimumSwaps = min(minimumSwaps, requiredSwaps);
        }
        return minimumSwaps;
    }
};