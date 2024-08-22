class Solution {
public:
    int findComplement(int num) {
        string num1 = toBinary(num);
        
        // Flipping the bits
        for (int i = 0; i < num1.length(); i++) {
            num1[i] = (num1[i] == '0') ? '1' : '0';
        }
        
        return toDecimal(num1);
    }

    string toBinary(int n) {
        string r;
        while (n != 0) {
            r = (n % 2 == 0 ? "0" : "1") + r;
            n /= 2;
        }
        return r;
    }

    int toDecimal(string n) {
        int r = 0;
        for (auto c : n) {
            r = r * 2 + (c - '0');
        }
        return r;
    }
};
