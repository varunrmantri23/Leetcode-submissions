class Solution {
public:
    int maxArea(vector<int>& heights) {
        //area should be maximised so we have to keep in mind both height and width

        //sliding window?
        //two-pointer we will just see min or l and r and then the distance between them and maximise that
        int l = 0;
        int r = heights.size() - 1;
        int answer = 0;
        while(l < r){
            int h =  min(heights[l], heights[r]);
            int w =  r - l;
            answer = max(answer, h * w);
            if(heights[l] < heights[r])
                l++;
            else r--;
        }
        return answer;
    }
};
