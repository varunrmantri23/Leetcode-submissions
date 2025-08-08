class Solution {
public:
    double helper(int A, int B, vector<vector<double>> &dp){
        if(A <= 0){
            if(B > 0){
                return 1.0;
            }
            else{
                return 0.5;
            }
        }
        else if(B <= 0){
            return 0.0;
        }
        if(dp[A][B] != -1) return dp[A][B];
        return dp[A][B] = 0.25 * (helper(A - 100, B,dp) +helper(A - 75, B - 25,dp)+helper(A - 50, B - 50,dp)+helper(A - 25, B- 75,dp));
    }
    double soupServings(int n) {
        if(n >= 5000) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1,-1));
        return helper(n, n,dp);
    }
};