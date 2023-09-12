class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> charfrequencies;

        unordered_set<int> existingfrequencies;

        for( char c :s){
            charfrequencies[c]++;
        }

        priority_queue<int> maxheap;

        for( auto freq : charfrequencies){
            maxheap.push(freq.second);
            // cout<<freq.first<<endl;
            // cout<<freq.second<<endl;
        }

        int deletions = 0;
        while(!maxheap.empty()){
            int currfreq = maxheap.top();
            maxheap.pop();

            while(currfreq > 0 && existingfrequencies.count(currfreq)){
                currfreq--;
                deletions++;
            }
            existingfrequencies.insert(currfreq);

        }
         return deletions;

    }
};