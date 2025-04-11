class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high;i++){
            if(isSymmetric(to_string(i))) ans++;
        }
        return ans;
    }
    bool isSymmetric(string s){
        int n  = s.size();
        if(n % 2 == 1) return false;
        int x = n/2;
        int sumFirst = 0;
        int sumSecond = 0;
        int counter = 0;
        while(counter < n){
            if(counter < x){
                sumFirst += (s[counter] - '0');
            }
            else sumSecond += (s[counter] - '0');
            counter++;
        }
        return sumFirst == sumSecond;
    }
};