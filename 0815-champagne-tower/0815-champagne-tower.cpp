class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Initialize the current level with the poured amount in the top glass
        std::vector<double> currentLevel(1, poured);
        
        // Traverse each row up to the target row
        for (int row = 0; row < query_row; row++) {
            // Initialize the next level with the appropriate number of glasses for the current row
            std::vector<double> nextLevel(row + 2, 0.0);
            
            // Traverse each glass in the current level
            for (int glass = 0; glass < currentLevel.size(); glass++) {
                // Calculate overflow and distribute it to the adjacent glasses in the next level
                double overflow = (currentLevel[glass] - 1.0) / 2.0;
                if (overflow > 0.0) {
                    nextLevel[glass] += overflow;
                    nextLevel[glass + 1] += overflow;
                }
            }
            
            // Update the current level with the next level for the next iteration
            currentLevel = nextLevel;
        }
        
        // Return the drink level in the target glass (clamped to 1.0 if overflowed)
        return std::min(1.0, currentLevel[query_glass]);
    }
};