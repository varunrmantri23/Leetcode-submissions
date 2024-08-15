class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarBills = 0;
        int tenDollarBills = 0;
        
        for (int customerBill : bills) {
            if (customerBill == 5) {
                fiveDollarBills++;
            } else if (customerBill == 10) {
                if (fiveDollarBills > 0) {
                    fiveDollarBills--;
                    tenDollarBills++;
                } else {
                    return false;
                }
            } else {
                if (tenDollarBills > 0 && fiveDollarBills > 0) {
                    fiveDollarBills--;
                    tenDollarBills--;
                } else if (fiveDollarBills >= 3) {
                    fiveDollarBills -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};