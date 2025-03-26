class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //we need somewhere in mid to make less operations, sort -> mid , 
        //median <>
        //So find Floor(L/2) -> make every element as that 
        //a+3x = target that means target - a / x is divisiible, so % = 0 
        //target - a = kx
        //target%x = a%x
        int n = grid.size();
        int m = grid[0].size();
        int operations = 0;
        vector <int> vec;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++)
                vec.push_back(grid[i][j]);
        }
        
        int L = vec.size(); //n*m
        // sort(vec.begin(), vec.end()); //O(LlogL)
        nth_element(begin(vec), begin(vec)+ L/2, end(vec));
        
        int target = vec[L/2];
        //cout << target << endl;
        
        for(int &num : vec){
            if(num%x != target%x) 
                return -1;
            else{
                operations += abs(num-target)/x;
            }
        }

        return operations;
    }
};