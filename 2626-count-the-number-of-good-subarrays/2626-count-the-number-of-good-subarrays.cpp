class Solution {
public:
    
    #define ll long long
    
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        
        ll int pairs_count=0;
        
        map<int,int> mp;
        int i=0, j=0;
        
        ll int ans=0;
        while(j<n){
            mp[nums[j]]++;
            
            pairs_count += mp[nums[j]]-1; // number of new pairs formed 
            
            while(i<j && pairs_count >= k){
                 ans += n-j; // if for [i,j] we have pairs_count >= k, so all idx => [j,n-1] can be included in answer
                
                mp[nums[i]]--;
                pairs_count -= mp[nums[i]];
                
                i++;
            }
            j++;
        }
        
        return ans;
    }
};