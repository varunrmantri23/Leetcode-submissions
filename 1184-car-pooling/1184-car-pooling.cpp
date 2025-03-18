class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //so when any number or passengers enter, they will reach when destination comes, 
        //when in between the inital to and from, other people come ,
        //they can take car according to capacity , if not then return false -  not possible

        //approach - sort to and from and then check with pointers?
        vector<pair<int,int>> v;
        for(int i =0; i < trips.size(); i++){
            v.push_back({trips[i][1],trips[i][0]}) ; // pushing fromi , numPassengersi
            v.push_back({trips[i][2],-trips[i][0]}) ; // pushing toi , -numPassengersi
        }

        sort(v.begin(),v.end());

        int curr = 0;
         
        for(int i=0;i<v.size();i++)
        {
            curr+=v[i].second ;
            
            if(curr>capacity)
                return false ;
        }

        return true;
    }
};