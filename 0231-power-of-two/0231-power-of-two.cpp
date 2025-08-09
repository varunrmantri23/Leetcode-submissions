class Solution {
public:

    bool isPowerOfTwo(int n) {
        if(n < 0){
            return false;
        }
        int count = 0;
        for(int i = 0; i < 32;i++){
            if(1&(n >> i)){
                count++;
            }
        }
        return (count == 1);
    }
};