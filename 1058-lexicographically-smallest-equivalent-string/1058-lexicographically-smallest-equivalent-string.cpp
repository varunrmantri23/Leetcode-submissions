class Solution {
public:
    int representative[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    void unite(int a, int b){
        int finda = find(a);
        int findb = find(b);
        if (representative[b] > representative[a])
            representative[findb] = finda;
        else representative[finda] = findb;
    }

    int find(int x){
        if (representative[x] == x)
            return representative[x];
        representative[x] = representative[representative[x]];
        return representative[x];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < s1.length(); i++){
            for(int j = 0; j < s2.length(); j++){
                if (i == j)
                    unite(s1[i]- 'a', s2[j] - 'a');
            }
        }
        for(int k = 0; k < baseStr.length(); k++)
        {
            baseStr[k] = find(baseStr[k] - 'a') + 'a';
        }
        return baseStr;
    }
};