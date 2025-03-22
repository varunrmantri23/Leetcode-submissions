class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Adjacency lists for each vertex
        vector<vector<int>> graph(n);

        // Build adjacency lists from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int completeCount = 0;
        unordered_set<int> visited;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (visited.count(vertex)) continue;

            // arr[0] = vertices count, arr[1] = total edges count
            int componentInfo[2] = {0, 0};
            dfs(vertex, graph, visited, componentInfo);

            // Check if component is complete - edges should be vertices *
            // (vertices-1)
            if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                completeCount++;
            }
        }
        return completeCount;
    }

private:
    void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited,
             int componentInfo[2]) {
        visited.insert(curr);
        componentInfo[0]++;  // Increment vertex count
        componentInfo[1] +=
            graph[curr].size();  // Add edges from current vertex

        // Explore unvisited neighbors
        for (int next : graph[curr]) {
            if (!visited.count(next)) {
                dfs(next, graph, visited, componentInfo);
            }
        }
    }
};