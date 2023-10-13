class Solution {
public:
    int fib(int n) {
        int fib0 = 0;
        int fib1 = 1;
        if(n == 0) return fib0;
        if(n == 1) return fib1;
        for(int i = 2; i < n; i++){
            int temp = fib1;
            fib1 = fib0 + fib1;
            fib0 = temp;
        }
        return fib1+fib0;
    }
};