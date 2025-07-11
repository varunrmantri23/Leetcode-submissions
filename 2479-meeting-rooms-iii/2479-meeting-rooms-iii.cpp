class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //sort meetings so that we can assign based on start times
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        // need to store when room finishes in some ds
        // min-heap for when room ends
        //if found empty round, assign, if not, then select next free room which gets free first among others
        vector<int> roomUsedCount(n,0); //room used how many times
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for(int room = 0; room < n; room++){
            availableRooms.push(room);
        }
        //all rooms are available initially so push
        for(vector<int> &meet : meetings){
            int start = meet[0];
            int end = meet[1];

            //first check all used rooms which are free and shift to free
            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else {
                //no room empty rn
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end-start) ,room});
                roomUsedCount[room]++;
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