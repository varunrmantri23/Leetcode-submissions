class Solution {
public:
    int sumOfDigits(int n) {
        if (n == 0)
            return 0;
        return (n % 10) + sumOfDigits(n / 10);
    }
    int countLargestGroup(int n) {
        vector<int> x(n, 0);
        for (int i = 1; i <= n; i++){
            int y = sumOfDigits(i);
            x[y-1]++;
        }
        int maxSize = 0;
        int answer = 0;
        for(int j = 0;j < n; j++){
            if(x[j] == maxSize) answer++;
            if(x[j] > maxSize){
                maxSize = x[j];
                answer = 1;
            }
        }
        return answer;
    }
};