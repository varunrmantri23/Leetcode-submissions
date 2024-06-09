class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
	    vector<int>pref(k,0);
	    int sum=0;
	    pref[0]++;
	    for(int i=0;i<n;i++){
	        sum+= nums[i];
	        int rem=(sum%k+k)%k;
	        ans+=pref[rem];
	        pref[rem]++;
	    }
	    return ans;
    }
};