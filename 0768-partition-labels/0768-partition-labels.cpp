class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> answer;

        vector<int> map(26,0);
        for(int i = (int)s.length() - 1; i >= 0 ; i--){
            if(map[s[i] - 'a'] == 0 ){
                map[s[i] - 'a'] = i;
            }
        }
        cout<<"what";

        int l = 0, r = 0;
        int start  = 0;
        while(l < (int)s.length() && r < (int)s.length()){
            r = max(map[s[l] - 'a'], r);
            cout<<"why"<<r;
            if(l == r) {
                answer.push_back(r-start + 1);
                start = r + 1;
            }
            l++;
        }
        return answer;
    }
};