class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> sortedArrivalTimes(people.begin(), people.end());
        sort(sortedArrivalTimes.begin(), sortedArrivalTimes.end());

        // Sort the flower intervals based on their start times.
        sort(flowers.begin(), flowers.end()) ;
        
        unordered_map<int, int> bloomCounts;  // Map to store counts of flowers in bloom for each arrival time.
        priority_queue<int, vector<int>, greater<int>> bloomEndTimes;  // Min heap to track flower bloom end times.

        int flowerIdx = 0 ;
        for(int personTime: sortedArrivalTimes){
            // Add flowers that are in bloom at the person's arrival time.
            while(flowerIdx < flowers.size() && flowers[flowerIdx][0] <= personTime)
                bloomEndTimes.push(flowers[flowerIdx++][1]);

            // Remove flowers that are no longer in bloom.
            while(!bloomEndTimes.empty() && bloomEndTimes.top() < personTime)
                bloomEndTimes.pop();

            // Store the count of flowers in bloom for the person's arrival time.
            bloomCounts[personTime] = bloomEndTimes.size();
        }

        vector<int> flowerCounts;  // Resulting array to store flower counts for each person.
        for(int arrivalTime: people)
            flowerCounts.push_back(bloomCounts[arrivalTime]);

        return flowerCounts;  // Return the counts of flowers in bloom for each person's arrival time.
    }
};