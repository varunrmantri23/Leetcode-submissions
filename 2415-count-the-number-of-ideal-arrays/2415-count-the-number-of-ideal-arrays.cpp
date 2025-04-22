class Solution 
{
    const int MOD = 1e9 + 7;
    vector<int> fact, invFact;

public:
    int idealArrays(int n, int maxValue) 
    {
        int maxLen = n + 100;

        // Step 1: Precompute factorials and inverse factorials
        computeFactorials(maxLen);

        // Step 2: Precompute smallest prime factors
        vector<int> spf = sieve(maxValue);
        long long result = 0;

        // Step 3: Iterate over each number as ending element
        for (int num = 1; num <= maxValue; ++num) 
        {
            unordered_map<int, int> primeCounts = primeFactorize(num, spf);
            long long ways = 1;

            // Step 5: Apply stars and bars for each prime exponent
            for (auto& [p, exp] : primeCounts) 
            {
                ways = ways * comb(n + exp - 1, exp) % MOD;
            }

            // Step 6: Accumulate result
            result = (result + ways) % MOD;
        }

        // Step 7: Return result
        return (int)result;
    }

private:
    // Step 1: Precompute factorials and inverse factorials
    void computeFactorials(int maxLen) 
    {
        fact.resize(maxLen);
        invFact.resize(maxLen);
        fact[0] = 1;

        // 1a: Compute factorials
        for (int i = 1; i < maxLen; ++i) 
        {
            fact[i] = (long long)fact[i - 1] * i % MOD;
        }

        // 1b: Inverse of last factorial
        invFact[maxLen - 1] = modInverse(fact[maxLen - 1]);

        // 1c: Inverse factorials in reverse
        for (int i = maxLen - 2; i >= 0; --i) 
        {
            invFact[i] = (long long)invFact[i + 1] * (i + 1) % MOD;
        }
    }

    // Step 2: Sieve to compute smallest prime factor for each number
    vector<int> sieve(int limit) 
    {
        vector<int> spf(limit + 1);
        for (int i = 2; i <= limit; ++i) 
        {
            if (spf[i] == 0) 
            {
                for (int j = i; j <= limit; j += i) 
                {
                    if (spf[j] == 0)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    // Step 4: Factorization using smallest prime factors
    unordered_map<int, int> primeFactorize(int num, const vector<int>& spf) 
    {
        unordered_map<int, int> map;
        while (num > 1) 
        {
            int p = spf[num];
            map[p]++;
            num /= p;
        }
        
        return map;
    }

    // Step 5: Combinatorics with precomputed factorials
    long long comb(int a, int b) 
    {
        if (b > a)
        {
            return 0;
        } 
        
        return (long long)fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    }

    // Modular inverse via binary exponentiation
    int modInverse(int x) 
    {
        return powMod(x, MOD - 2);
    }

    // Binary exponentiation
    int powMod(int a, int b) 
    {
        long long res = 1, base = a;
        while (b > 0) 
        {
            if (b & 1)
            {
                res = res * base % MOD;
            }

            base = base * base % MOD;
            b >>= 1;
        }
        
        return (int)res;
    }
};