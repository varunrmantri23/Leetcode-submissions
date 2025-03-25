class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < result.back()[1]) {
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else
                result.push_back(intervals[i]);
        }
        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //we have to merge for horizontal and vertical so extract that from given rectangles and then work on it
        vector<vector<int>> x;
        vector<vector<int>> y;

        for(int i = 0; i < rectangles.size(); i++){
            x.push_back({rectangles[i][0],rectangles[i][2]});
            y.push_back({rectangles[i][1],rectangles[i][3]});
        }
        vector<vector<int>> hor = merge(x);
        vector<vector<int>> ver = merge(y);

        return (hor.size() > 2 || ver.size() > 2);
    }
};