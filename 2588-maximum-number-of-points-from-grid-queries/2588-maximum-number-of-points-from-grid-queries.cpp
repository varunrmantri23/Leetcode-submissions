class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        //so we see if query is small and we get x ans, we will get x+y for any query bigger, so we can sort and find then store position as well and do bfs 
        //sort with positions
        int row = grid.size(), col = grid[0].size();
        vector<int> result(queries.size(), 0);
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<pair<int, int>> sortedq;
        for (int i = 0; i < queries.size(); i++) {
            sortedq.push_back({queries[i], i});
        }
        //sort as decided :)
        sort(sortedq.begin(),sortedq.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        //maintain visited so we dont count inpair<int, pair<int, int>> answer 
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int totalPoints = 0;

        //inital element add 
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        for (auto [queryvalue, queryindex] : sortedq) {
            // expand all cells with value less than the current query value
            while (!minHeap.empty() && minHeap.top().first < queryvalue) {
                auto [cellValue, pos] = minHeap.top();
                minHeap.pop();
                int currentRow = pos.first, currentCol = pos.second;
                // increment count as valid
                totalPoints++;
                
                // explore all four directions
                for (auto [r, c] : DIRECTIONS) {
                    int newRow = currentRow + r, newCol = currentCol + c;
                    // check bounds and ensure cell not visited
                    if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !visited[newRow][newCol]) {
                        minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            // store answer for the query at its original index
            result[queryindex] = totalPoints;
        }

        return result;

    }
};