class Solution {
public:
    int minDeletions(string s) {
        // Create an array to store character frequencies (one for each letter of the alphabet)
        vector<int> charFrequency(26) ;
        
        // Create a set to keep track of existing frequencies in new string
        unordered_set<int> existingFrequencies;
        
        // Count character frequencies
        for (char c : s) {
            charFrequency[c - 'a']++;
        }
        
        int deletions = 0 ;
        // Iterate through the sorted frequencies
        for(int i = 0 ; i < charFrequency.size() ; i ++){
            int curFreq = charFrequency[i] ;
            
            // Adjust frequency if it already exists in the new string
            while(curFreq > 0 && existingFrequencies.find(curFreq) != existingFrequencies.end()){
                deletions ++ ;
                curFreq -- ;
            }
            // Add the adjusted frequency to the set
            existingFrequencies.insert(curFreq) ;
        }

        return deletions;
    }
};