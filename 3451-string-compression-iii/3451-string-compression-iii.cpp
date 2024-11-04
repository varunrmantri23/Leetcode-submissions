class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char x = word[0];
        int counter = 1;
        for(int i = 1;i < word.length();i++){
            if(x == word[i] && counter < 9){
                counter++;
            }
            else if(x!=word[i]){
                comp += to_string(counter);
                comp += x;
                x = word[i];
                counter = 1;
            }
            else if(x==word[i] && counter == 9){
                comp += to_string(counter);
                comp += x;
                x = word[i];
                counter = 1;
            }
            
        }
        comp += to_string(counter);
        comp += x;

        return comp;
    }
};