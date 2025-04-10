class Solution {

public:
    long long count_valid(long long n, int limit) {
        string str = to_string(n);
        int len = str.size();
        vector<vector<long long>> dp(len+1, vector<long long>(2, -1));
        
        function<long long(int,int)> rec = [&](int pos, int tight) -> long long {
            if(pos == len)
                return 1;
            if(dp[pos][tight] != -1) return dp[pos][tight];
            long long ways = 0;
            int up = (tight ? (str[pos]-'0') : limit);
            // adjust if the current digit of n is higher than limit in a tight state:
            if(tight && (str[pos]-'0') > limit)
                up = limit;
            for(int d = 0; d <= up; d++){
                int ntight = (tight && (d == (str[pos]-'0')));
                ways += rec(pos+1, ntight);
            }
            dp[pos][tight] = ways;
            return ways;
        };
        
        return rec(0, 1);
    }
    // returns count of powerful integers <= x
    long long solve(long long x, int limit, string s) {
        long long suf = stoll(s);
        int m = s.size();
        long long base = 1;
        for (int i = 0; i < m; i++) {
            base *= 10;
        }
        if (x < suf) return 0;
        long long tmax = (x - suf) / base;
        return count_valid(tmax, limit);
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(finish, limit, s) - solve(start - 1, limit, s);
    }
};

