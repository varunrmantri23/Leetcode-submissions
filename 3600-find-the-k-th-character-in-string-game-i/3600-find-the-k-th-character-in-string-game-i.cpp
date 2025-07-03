class Solution {
public:
    char kthCharacter(int k) {
        int currLen = 1;
        string final = "a";
        while(final.length() < k){
            string append = "";
            for(int i = 0; i < final.length(); i++){
                append.push_back(final[i] + 1);
            }
            final += append;
        }
        return final[k-1];
    }
};