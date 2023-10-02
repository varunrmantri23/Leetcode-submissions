class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        for(int i = 1; i < (colors.length() - 1);i++){
            if(colors[i] == 'A'&& colors[i-1] == 'A' && colors[i+1] == 'A' ){
                alice += 1;
            }
            else if(colors[i] == 'B'&& colors[i-1] == 'B' && colors[i+1] == 'B' ){
                bob += 1;
            }
        }
        if(alice > bob ) return true;
        else return false;
    }
};