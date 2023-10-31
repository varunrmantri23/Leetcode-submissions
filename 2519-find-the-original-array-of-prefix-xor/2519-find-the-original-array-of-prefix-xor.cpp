class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>old(n,0);
        old[0] = pref[0];
        for(int i =1; i <n;i++){
            old[i] = pref[i]^pref[i-1];
        }
        return old;
    }
};