#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int oneStep = cost[1];
        int twoStep = cost[0];

        for (int i = 2; i < n; i++) {
            int currentStep = cost[i] + std::min(oneStep, twoStep);
            twoStep = oneStep;
            oneStep = currentStep;
        }

        return std::min(oneStep, twoStep);
    }
};
