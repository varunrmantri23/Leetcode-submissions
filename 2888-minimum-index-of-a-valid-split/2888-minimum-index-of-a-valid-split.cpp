class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //we can store frequency and then make sure that both splits have same digit as dominant element
        //majority element
        int x = nums[0], count = 0, xCount = 0, n = nums.size();
        for (auto& num : nums) {
            if (num == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        //freq of majority element
        for (auto& num : nums) {
            if (num == x) {
                xCount++;
            }
        }

        // valid split or not
        count = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] == x) {
                count++;
            }
            int remainingCount = xCount - count;
            if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                return index;
            }
        }
        return -1; //not valid

    }
};