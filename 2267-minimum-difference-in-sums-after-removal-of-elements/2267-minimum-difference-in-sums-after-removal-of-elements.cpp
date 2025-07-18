class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;

        vector<long long> leftMinSum(N,0);
        vector<long long> rightMaxSum(N,0);

        priority_queue<long long> maxHeap;
        long long maxLeft = 0;
        for(int i = 0; i < 2*n;i++){
            maxHeap.push(nums[i]);
            maxLeft += nums[i];
            if(maxHeap.size() > n){
                maxLeft -= maxHeap.top();
                maxHeap.pop();
            }
            leftMinSum[i] = maxLeft;
        }

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long minRight = 0;
        for(int i = N-1; i >= n;i--){
            minHeap.push(nums[i]);
            minRight += nums[i];
            if(minHeap.size() > n){
                minRight -= minHeap.top();
                minHeap.pop();
            }
            rightMaxSum[i] = minRight;
        }

        long long result = LLONG_MAX;
        for(int i = n-1; i < 2*n;i++){
            result = min(result, leftMinSum[i] - rightMaxSum[i+1]);
        }

        return result;
    }
};