class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> freeTime;
        // k shifts possible
        if (startTime[0] > 0) {
            freeTime.push_back(startTime[0] - 0);
        }
        for (int i = 1; i < startTime.size(); i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[startTime.size() - 1]);

        // now we have our free times, we need to select max k+1 continuous free
        // times;
        if (freeTime.empty())
            return 0;
        int l = 0;
        int maxFreeTime = 0;
        int currFreetime = 0;
        for (int r = 0; r < freeTime.size(); r++) {
            currFreetime += freeTime[r];
            while (r - l + 1 > k + 1) {
                currFreetime -= freeTime[l];
                l++;
            }
            maxFreeTime = max(maxFreeTime, currFreetime);
        }
        return maxFreeTime;
    }
};