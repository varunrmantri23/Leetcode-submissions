class Solution {
public:
    int trap(vector<int>& height) {
       //two-pointer approach 
       int n = height.size();
       if (n < 3) return 0;

       int answer = 0;
       int maxleft = height[0];
       int maxright = height[n -1];
       int l = 0, r =  n - 1;
       while(l < r){
        if(maxleft < maxright) {
            l++;
            maxleft = max(height[l],maxleft);
            answer += maxleft - height[l]; 
        }
        else {
            r--;
            maxright = max(height[r],maxright);
            answer += maxright - height[r];
        }
       } 
       return answer;
    }
};
