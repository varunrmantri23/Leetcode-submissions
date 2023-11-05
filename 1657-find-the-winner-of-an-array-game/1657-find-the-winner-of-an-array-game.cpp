#include <bits/stdc++.h>
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int count = 0;
        int winner = arr[0];
        int size = arr.size();
        if(size == 2){
            return (arr[0]>=arr[1]) ? arr[0] : arr[1];
        }
        if(k >= size - 1) return *max_element(arr.begin(), arr.end());
        for(int i =1;i < size;i++){
            if(winner>=arr[i]){
                count++;
            }
            else if(winner<arr[i]){
                count = 1;
                winner = arr[i];
            }
            if(count == k){
                return winner;
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};
