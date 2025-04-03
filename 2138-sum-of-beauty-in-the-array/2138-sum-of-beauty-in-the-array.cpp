class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        //we can see if at any i , j(prev) max is smaller than i 
        //or k(ahead) min is greater than i, that means for all j behind and all k ahead, cond 1 satisfied, so +2
        //now if this is not the case , second condition is just if else
        //else 0
        //we can go over two pass sol
        int n = nums.size();
        vector <int> leftMax(n, 0);
        int ans = 0;
        leftMax[0] = nums[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(nums[i], leftMax[i-1]);
        }

        int Rmin = nums[n-1];
        for(int k = n -2; k >= 1; k--){
            if(Rmin > nums[k] && leftMax[k-1] < nums[k]) ans+=2;
            else if(nums[k+1] > nums[k] && nums[k] > nums[k-1]) ans+=1;
            Rmin = min(Rmin, nums[k]);
        }
        return ans;
    }
};