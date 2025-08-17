class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n+1,0.0);
        P[0] = 1; //base case only 1 possibility
        double probSum = (k == 0 ? 0:1);
        for(int i = 1; i < n+1;i++){
            P[i] = probSum/maxPts;
            if(i < k){
                probSum += P[i];
            }
            if(i-maxPts >= 0 && i-maxPts < k){
                probSum -= P[i-maxPts];
            }
        }
        return accumulate(P.begin()+k, P.end(), 0.0); //this means take all values for consideration when we get k points or more 
    }
};