class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //we want i to be maximum, then k and minimum j
        //what we can do is pre - compute left max and right max of any j, and then iterate over and calculate maximum value
        int n = nums.size();
        if(n < 3) return 0;

        long long tmax = nums[0];
        long long tmax_ = nums[n-1];
        
        vector <int> Lmax(n, 0);
        vector <int> Rmax(n, 0);
        
        Lmax[0] = -1;
        for(int i = 1; i < n;i++){
            Lmax[i] = tmax;
            tmax = max(tmax, (long long)nums[i]);
        }
        
        Rmax[n-1] = -1;
        for(int j = n -2; j >= 0; j--){
            Rmax[j] = tmax_;
            tmax_ = max(tmax_, (long long)nums[j]);
        }
        
        long long answer = 0;
        for(int k = 1; k < n - 1; k++){
            answer = max(answer, (long long)(Lmax[k] - nums[k]) * Rmax[k]);
        }
        
        return answer;
    }
};