class Solution {
private: 
    long long solve(int l, int r){
        long long L = 1;
        long long S = 1;
        long long steps = 0;
        while(L <= r){
            long long R = 4*L - 1;

            long long start = max((long long)l,L);
            long long end = min((long long)r,R);

            if(start <= end){
                steps += (end-start+1)*S;
            }
            S+=1;
            L = L*4;
        }
        return steps;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        //1 to 3 - 1 step
        //4 to 15 - 2 step
        //16 to 63 - 3 step .. so on , that means -> 4powers so we can take log
        // s steps -> 4^s-1 range to 4^s - 1 -> imp observation
        long long res = 0;
        for(auto &query : queries){
            int l = query[0];
            int r = query[1];
            long long steps = solve(l,r);
            res += (steps+1)/2;
        }   
        return res;
    }
};