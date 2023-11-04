class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if (left.empty() && right.empty()) {
            return n; // No ants on the rod.
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        if (left.empty()) {
            return n - right[0]; // All ants on the right side.
        }

        if (right.empty()) {
            return left.back(); // All ants on the left side.
        }



        int leftLastFallTime = left.back();
        int rightFirstFallTime = n - right[0];

        return max(leftLastFallTime, rightFirstFallTime);
    }
};
