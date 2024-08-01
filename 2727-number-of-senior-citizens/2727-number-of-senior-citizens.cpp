class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        for (string& passengerInfo : details) {
            int ageTens = passengerInfo[11] - '0';
            int ageOnes = passengerInfo[12] - '0';

            int age = ageTens * 10 + ageOnes;

            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};