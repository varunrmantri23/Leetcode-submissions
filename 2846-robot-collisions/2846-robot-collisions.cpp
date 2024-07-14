class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        
        
         vector<pair<int,int>>vp ;
          int n=pos.size() ;
         for(int  i=0;i<n;i++) {
             
             vp.push_back({pos[i],i}) ;
         }
        
        sort(vp.begin(),vp.end()) ;
        
         stack<int>st ;
         
         
         for(int i=0;i<n;i++) {
              int ind=vp[i].second ;
               char dir=d[ind] ;
               
               if(dir=='L') {
                  
                    if(st.empty()) {
                        st.push(ind) ;  
                    }
                   else {
                       
                        if(d[st.top()]=='R' && h[st.top()] ==h[ind]) {
                             h[st.top()]=0 ;
                             st.pop() ;
                             h[ind]=0 ;
                           
                        }
                       else{ 
                       
                        while(!st.empty() && d[st.top()]=='R' && h[st.top()] < h[ind] ){
                             h[st.top()]=0 ;
                            st.pop();
                            h[ind]--;
                        }
                       // left robot moving in right direction and health is greater than curr robot
                        if(!st.empty() &&  d[st.top()]=='R' && h[st.top()] > h[ind]) {
                            h[st.top()]--; 
                            h[ind]=0 ;
                        }
                       // left robot moving in right direction and health is  equal to curr robot
                          else  if(!st.empty() &&  d[st.top()]=='R' && h[st.top()] == h[ind]) {
                            h[st.top()]=0; 
                            h[ind]=0 ;
                                st.pop();
                        }
                       else{
                           st.push(ind) ;
                       }
                       }
                        
                   }
               } 
     // moving in right direction, collison is not possible with behind this robot
             else{
                 st.push(ind) ;     
             }
         }
        
         vector<int>ans;
        
         for(int x:h) {
             if(x >0) ans.push_back(x) ; 
         }
        
         return ans;
         
    }
};