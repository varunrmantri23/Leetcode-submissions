class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        //we know it ends with specific suffix so the prefix will have fixed possibilty
        //__ 124
        //so we can see first blank should range between given start and finish and also that digit has a limit
        //solve(finish) - solve(start-1) solve starts from 0 so we get our ans 
        //to string , easier to iterate
        
        //remaining length = finish.length - s.length
        
        string strt = to_string(start-1);
        string end = to_string(finish);
        
        return solve(end,s,limit) - solve(strt,s,limit);
    }

    long long solve(string &str, string &s, int limit){
        if(str.length() < s.length()) return 0;
        long long count = 0;
        string subStr = str.substr(str.length() - s.length());
        int remainingLen = str.length() - s.length();
        for(int i = 0; i < remainingLen; i++){
            int digit = str[i] - '0';

            if(digit <= limit ){
                count += digit * pow(limit+1, remainingLen - i -1);
            }
            else{
                count += pow(limit+1, remainingLen -i);
                return count;
            }
            
        }



        if(subStr >= s){
            count+=1;
        }

        return count;
    };
};