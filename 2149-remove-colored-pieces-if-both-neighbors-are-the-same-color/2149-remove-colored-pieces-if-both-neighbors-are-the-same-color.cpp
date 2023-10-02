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
        if((alice - bob) > 1) return true;
        else if((bob - alice) > 1) return false;
        if(alice - bob ==1) return true;
        else if (bob - alice == 1) return false;
        if(alice - bob == 0) return false;
        return false;
    }
};
//approach 1.st iterate all over and find consecutive a or b and store the (number -2), if number > 3, in alice variable or bob (a/b)(turns they will get) if alice variable is even and and bob is odd then she wins as she starts first