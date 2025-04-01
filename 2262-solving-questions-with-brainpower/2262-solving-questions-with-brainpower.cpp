class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return helper(0,questions, dp, n);
    }
    long long helper(int i, vector<vector<int>>& questions, vector<long long> &dp, int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        long long take = questions[i][0] + helper(i+questions[i][1] + 1, questions, dp, n);
        long long dont = helper(i+1, questions, dp, n);

        return dp[i] = max(take, dont);
    }
};
/* Hint 1
For each question, we can either solve it or skip it. How can we use Dynamic Programming to decide the most optimal option for each problem?
Hint 2
We store for each question the maximum points we can earn if we started the exam on that question.
Hint 3
If we skip a question, then the answer for it will be the same as the answer for the next question.
Hint 4
If we solve a question, then the answer for it will be the points of the current question plus the answer for the next solvable question.
Hint 5
The maximum of these two values will be the answer to the current question.
*/