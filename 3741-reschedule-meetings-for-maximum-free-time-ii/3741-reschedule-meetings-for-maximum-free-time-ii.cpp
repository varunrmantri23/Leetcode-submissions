class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        // 1 shift possible
        if (startTime[0] >= 0) {
            freeTime.push_back(startTime[0] - 0);
        }
        for (int i = 1; i < startTime.size(); i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[startTime.size() - 1]);

        // times;
        if (freeTime.empty())
            return 0;
        int maxFreeTime = 0;
        for(int num: freeTime){
            maxFreeTime = max(maxFreeTime, num);
        }
        int h = freeTime.size();
        //no event touched -> maxFreeTime
        //shift to adjacent or move to somewhere else
        //shift -> sliding window 2size , move -> adjancent free times + the event size (moved event)
        vector<int> freeLeft(h);
        vector<int> freeRight(h);
        int freeRightMax = 0;
        for(int i = h - 1; i >= 0; i--){
            freeRight[i] = freeRightMax;
            freeRightMax = max(freeRightMax, freeTime[i]);
        }
        int freeLeftMax = 0;
        for(int i = 0; i < h; i++){
            freeLeft[i] = freeLeftMax;
            freeLeftMax = max(freeLeftMax, freeTime[i]);
        }
        int res = 0;
        for(int i = 1; i < h;i++){
            int currEvent = endTime[i-1] - startTime[i-1];
            //case 1: move
            if(currEvent <= max(freeLeft[i-1],freeRight[i])){
                res = max(res, freeTime[i-1] + currEvent + freeTime[i]);
            }
            //case 2: shift
            res = max(res, freeTime[i-1]+ freeTime[i]);
        }
        return res;
    }
};