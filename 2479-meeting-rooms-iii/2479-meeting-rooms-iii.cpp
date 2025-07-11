class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //sort meetings so that we can assign based on start times
        sort(meetings.begin(), meetings.end());
        // need to store when room finishes in some ds
        // min-heap for when room ends
        //if found empty round, assign, if not, then select next free room which gets free first among others
        vector<long long> lastAvailableAt(n,0);
        vector<int> roomUsedCount(n,0); //room used how many times
        for(vector<int> &meeting: meetings){
            int start = meeting[0];
            int end = meeting[1];
            bool found = false;
            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;
            //find first available meeting room
            for(int room = 0; room < n; room++){
                if(lastAvailableAt[room] <= start){
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }
                if(lastAvailableAt[room] < earlyEndRoomTime){
                    earlyEndRoom = room;
                    earlyEndRoomTime = lastAvailableAt[room];
                }
            }
            //if not found room
            if(!found){
                //pick first free time
                lastAvailableAt[earlyEndRoom] += end - start;
                roomUsedCount[earlyEndRoom]++;
            }
        }
        int resultRoom = -1;
        int maxUse = 0;
        for(int room = 0; room < n;room++){
            int curr = roomUsedCount[room];
            if(curr > maxUse){
                maxUse = curr;
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};
