class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n,1);

        for(int i = 1; i < n;i++){
            if(ratings[i-1] < ratings[i] && candies[i-1] >= candies[i]){
                candies[i] = candies[i-1]+1;
            }
        }
        for(int j = n-2; j >= 0 ;j--){
            if(ratings[j+1] < ratings[j] && candies[j+1] >= candies[j]){
                candies[j] = candies[j+1]+1;
            }
        }
        int totalcandies = 0;
        for(int j = 0; j < n ;j++){
            totalcandies += candies[j];
        }

        return totalcandies;
    }
};