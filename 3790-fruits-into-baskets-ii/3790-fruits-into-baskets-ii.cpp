class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits,vector<int>& baskets){
       int unplaced=0;
       vector<bool> used(baskets.size(),false);
       for(int i = 0; i < fruits.size();i++){
            bool isPlacedFruit = false;
            for(int j =0; j < baskets.size();j++){
                if(!used[j] && fruits[i] <= baskets[j]){
                    used[j] =  true;
                    isPlacedFruit = true;
                    break;
                }
            }
            if(!isPlacedFruit){
                unplaced++;
            }
       }
       
       return unplaced;
    }
};