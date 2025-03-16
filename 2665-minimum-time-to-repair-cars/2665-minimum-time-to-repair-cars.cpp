class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        /*
        so we observe that r*n^2 will increase if both are greater, so we have to balance out to get optimal time by which all other mechanics also fix car
        first thought that comes to mind, is it greedy ? as we need smaller rank for more cars so that it can be done faster, but how do we decide that as we have to run parallel so lets think of binary search on time so that each mechanic can complete that time or before , we know 
        answer can be between min * total cars ^ 2 and 1;
        */
        long long low = 1, high = 1LL * cars * cars * ranks[0];

        while(low < high){
            long long mid = low + (high - low )/2;
            long long carsRepaired = 0;

            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);

            if (carsRepaired < cars)
                low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};