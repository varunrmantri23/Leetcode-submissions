class Solution {
private:
    int countDistinctPrimeFactors(int n) {
        int count = 0;
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) {
                n /= 2;
            }
        }

        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1)
            count++;
        return count;
    }

    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return (int)result;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0)
            return 1;

        priority_queue<pair<int, int>> maxValues;
        vector<int> rightLarge(n, n), LeftLarge(n, -1), primeScores(n, 0);
        stack<int> st, reverse;

        for (int i = 0; i < n; i++) {
            primeScores[i] = countDistinctPrimeFactors(nums[i]);
            maxValues.emplace(nums[i], i);
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[i] > primeScores[st.top()]) {
                rightLarge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!reverse.empty() &&
                   primeScores[i] >= primeScores[reverse.top()]) {
                LeftLarge[reverse.top()] = i;
                reverse.pop();
            }
            reverse.push(i);
        }

        int score = 1;
        const int MODULE = 1000000007;

        while (!maxValues.empty() && k > 0) {
            auto [val, idx] = maxValues.top();
            maxValues.pop();

            long long t =
                1LL * (rightLarge[idx] - idx) * (idx - LeftLarge[idx]);
            long long steps = min(t, (long long)k);

            int multiply = modPow(val, (int)steps, MODULE);
            score = (int)((1LL * score * multiply) % MODULE);

            k -= steps;
        }
        return score % MODULE;
    }
};
/* 
Hint 1.
First, for each number in nums, count its distinct prime factors. Use the Sieve of Eratosthenes to precompute primes up to the maximum value in nums and then factor each number to get its prime score.

Hint 2.
The computed prime score tells you the importance of a number. Higher prime scores mean the number is more valuable for multiplication.

Hint 3.
Next, for each index i in nums, determine how many subarrays where nums[i] is the maximum (or dominant) element. Use a monotonic stack to compute:
- left[i]: nearest index to the left where the prime score is greater than or equal to s[i] (set to -1 if none).
- right[i]: nearest index to the right where the prime score is greater than s[i] (set to n if none).

Hint 4.
For each index i, the number of subarrays where nums[i] is dominant is:
(i - left[i]) * (right[i] - i)
This gives you how many times you could potentially use nums[i] in your operations.

Hint 5.
Sort the elements of nums in descending order along with their indices. This lets you greedily pick the numbers that contribute most to the score.

Hint 6.
Loop through the sorted numbers. For each number, decide the number of operations to use:
operations = min(remaining k, number of subarrays where this number is dominant)
Then, reduce k by operations.

Hint 7.
Update your overall score by multiplying it by nums[i] raised to the power of operations. Since the numbers can be huge, perform the multiplication modulo 10⁹+7.

Hint 8.
For fast power calculations, implement binary exponentiation. For example:

while (exponent > 0) {
  if (exponent % 2 == 1) { res = (res * base) % MOD; }
  base = (base * base) % MOD;
  exponent /= 2;
}
return res;

This efficiently computes base^exponent mod MOD
*/