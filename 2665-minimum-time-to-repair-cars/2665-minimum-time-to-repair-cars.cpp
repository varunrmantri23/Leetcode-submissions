class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        /*
        so we observe that r*n^2 will increase if both are greater, so we have to balance out to get optimal time by which all other mechanics also fix car
        first thought that comes to mind, is it greedy ? as we need smaller rank for more cars so that it can be done faster, but how do we decide that as we have to run parallel so lets think of binary search on time so that each mechanic can complete that time or before , we know 
        answer can be between min * total cars ^ 2 and 1;
        */
        int minRank = ranks[0], maxRank = ranks[0];

        for(int rank: ranks){
            minRank = min(minRank,rank);
            maxRank = max(maxRank,rank);
        }

        vector<int> freq(101,0);
        for(int rank: ranks){
            minRank = min(minRank,rank);
            freq[rank]++;
        }

        long long low = 1, high = 1LL * minRank * cars * cars;

        while(low < high){
            long long mid = low + (high - low )/2;
            long long carsRepaired = 0;

            for (int rank = 1; rank <= maxRank; rank++) {
                carsRepaired +=
                    freq[rank] * (long long)sqrt(mid / (long long)rank);
            }

            if (carsRepaired >= cars) {
                high = mid; 
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
};