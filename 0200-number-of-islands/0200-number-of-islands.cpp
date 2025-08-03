class Solution {
public:
    void dfs(int row, int col,vector<vector<char>>& grid){
        int m =  grid.size();
        int n = grid[0].size();
        grid[row][col] = '0';
        vector<int>delRow = {+1,0,-1,0};
        vector<int>delCol = {0,+1,0,-1};
        for(int i = 0;i < 4;i++){
            int nr = row+delRow[i];
            int nc = col+delCol[i];
            if(nr >= 0 && nr <m && nc >= 0 && nc <n && grid[nr][nc] == '1'){
                dfs(nr,nc, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();

        int numOfIslands = 0;

        for(int i = 0; i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    numOfIslands++;
                    dfs(i,j,grid);
                }
            }
        }
        return numOfIslands;
    }
};