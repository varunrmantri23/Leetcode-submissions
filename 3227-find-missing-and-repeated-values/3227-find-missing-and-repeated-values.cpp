class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1, repeat = -1;

        // Store frequency of each number in the grid
        unordered_map<int, int> freq;
        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        // Check numbers from 1 to n^2 to find missing and repeated values
        for (int num = 1; num <= n * n; num++) {
            if (!freq.count(num)) {
                missing = num;  // Number not present in grid
            } else if (freq[num] == 2) {
                repeat = num;  // Number appears twice
            }
        }

        return {repeat, missing};
    }
};