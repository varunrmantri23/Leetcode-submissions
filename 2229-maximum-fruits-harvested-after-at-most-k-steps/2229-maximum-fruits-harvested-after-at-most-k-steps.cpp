class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // left -> (i) P-d(where p is starting position)
        // right -> (j) P + (k-2*d)
        // lower bound search for fruit positions -> lower_bound(i)
        // upper_bound(j) - 1 index
        // same but opp for other case when going right first then coming back
        // left -> (j) P+d
        // right -> (i) P - (k-2*d)
        // k-2*d >= 0 so d <= k/2

        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> positions(n);

        for (int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + ((i > 0) ? prefixSum[i - 1] : 0);
        }

        int ans = 0;
        for (int d = 0; d <= k / 2; d++) {

            //case 1
            int remain = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(positions.begin(), positions.end(), i) -
                       positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - 1 -
                        positions.begin();
            if (left <= right) {
                int total =
                    prefixSum[right] - ((left > 0) ? prefixSum[left - 1] : 0);
                ans = max(ans, total);
            }

            //case 2 
            j = startPos + d;
            i = startPos - remain;

            left = lower_bound(positions.begin(), positions.end(), i) -
                       positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) - 1 -
                        positions.begin();
            if (left <= right) {
                int total =
                    prefixSum[right] - ((left > 0) ? prefixSum[left - 1] : 0);
                ans = max(ans, total);
            }
        }
        return ans;
    }
};