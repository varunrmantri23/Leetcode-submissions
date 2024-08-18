class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =
                *uglyNumbersSet
                     .begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(
                uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};