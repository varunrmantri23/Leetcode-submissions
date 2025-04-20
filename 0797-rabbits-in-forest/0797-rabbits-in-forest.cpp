class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int total = 0;

        for (int ans : answers) {
            freq[ans]++;
        }
        for (auto& [k, count] : freq) {
            int groupSize = k + 1;
            int groups = ceil((double)count / groupSize);
            total += groups * groupSize;
        }

        return total;
    }
};