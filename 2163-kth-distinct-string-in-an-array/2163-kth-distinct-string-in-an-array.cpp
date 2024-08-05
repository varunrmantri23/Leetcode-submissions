class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> frequencyMap;
        for (string& str : arr) {
            frequencyMap[str]++;
        }

        for (string& str : arr) {
            if (frequencyMap[str] == 1) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};