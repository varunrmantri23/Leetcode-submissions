class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        //sort the events array to process events according to their startTime
        sort(events.begin(),events.end());
        int ans=0;
        //Min-Priority queue will store the endTime of events in the increasing order of endTime
        //i.e Event with minimum endTime on top
        priority_queue<int,vector<int>,greater<int>> pq;
        int k=0;
        for(int i=1;i<=1e5;i++){
            //pop out all the days having endTime less than i
            //because those events are already ended and will not be valid on current day i
            while(!pq.empty() && pq.top()<i)pq.pop();

            //now add all the events endTime in pq with startTime equal to i 
            while(k<n && events[k][0]==i){
                pq.push(events[k][1]);
                k++;
            }
            
            //if there is no element in the pq there is no events to be attended, so continue 
            if(pq.empty())continue;

            //Otherwise add 1 to answer (a valid event is present)
            ans+=1;
            //pop the event (so that it cannot be counted again)
            pq.pop();
        }

        return ans;
    }
};