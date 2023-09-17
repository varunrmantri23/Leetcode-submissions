class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int numNodes = graph.size();
        int allVisitedMask = (1 << numNodes) - 1;
        queue<pair<int, pair<int, int>>> q;
        
        // Initialize visited array
        bool visited[allVisitedMask + 1][numNodes];
        memset(visited, false, sizeof visited);

        // Start from each node and add it to the queue as a starting point
        for (int node = 0; node < numNodes; ++node) {
            int initialMask = (1 << node);
            q.push({node, {initialMask, 1}});
            visited[initialMask][node] = true;
        }

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int currentNode = current.first;
            int currentMask = current.second.first;
            int currentLength = current.second.second;

            // Check if all nodes have been visited
            if (currentMask == allVisitedMask)
                return currentLength - 1;

            // Explore the neighbors of the current node
            for (int i = 0; i < graph[currentNode].size(); ++i) {
                int neighbor = graph[currentNode][i];
                int newMask = currentMask | (1 << neighbor);

                // Check if this state has been visited before
                if (visited[newMask][neighbor])
                    continue;

                // Add the neighbor to the queue with updated state
                q.push({neighbor, {newMask, currentLength + 1}});
                visited[newMask][neighbor] = true;
            }
        }
        return -1;  // No valid path found
    }
};