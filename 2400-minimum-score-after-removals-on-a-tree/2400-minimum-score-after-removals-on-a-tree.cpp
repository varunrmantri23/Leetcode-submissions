class Solution {
public:
    bool ancestor(int u, int v, vector<int>& in, vector<int>& out) {
        return in[u] < in[v] && out[u] > out[v];
    }

    int dfs(int currNode, vector<int>& nums, vector<vector<int>>& graph,
            vector<int>& xorResult, int time, vector<int>& timing_in,
            vector<int>& timing_out, int parent = -1) {
        int currXor = nums[currNode];
        timing_in[currNode] = time++;
        for (auto childNode : graph[currNode]) {
            if (childNode == parent) continue;
            time = dfs(childNode, nums, graph, xorResult, time, timing_in,
                       timing_out, currNode);
            currXor ^= xorResult[childNode];
        }
        xorResult[currNode] = currXor;
        timing_out[currNode] = time++;
        return time;
    }
    // int dfs(int currNode, vector<int>& nums, vector<vector<int>>& graph,
    //         vector<int>& xorResult, int time, vector<int>& timing_in,
    //         vector<int>& timing_out) {
    //     int currXor = nums[currNode];
    //     timing_in[currNode] = time++;
    //     for (auto childNode : graph[currNode]) {
    //         xorResult[currNode] = -2;
    //         if (xorResult[childNode] || xorResult[childNode] == -2)
    //             continue;
    //         time = dfs(childNode, nums, graph, xorResult, time, timing_in,
    //                    timing_out);
    //         currXor = currXor ^ xorResult[childNode];
    //     }
    //     xorResult[currNode] = currXor;
    //     timing_out[currNode] = time++;
    //     return time;
    // }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        // maintain timing while doing dfs and returning if we want to check
        // ancestors just check if timing[in] or out lies between ancestors
        // timing[in or out];
        vector<int> timing_in(n);
        vector<int> timing_out(n);

        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int result = -1;
        vector<int> xorResult(n);
        // so first steps first, lets find xor of each subtree at its node
        // we dfs
        dfs(0, nums, graph, xorResult, 0, timing_in, timing_out);
        // we select two nodes and decide to let them go
        // we use 0 as it will be part of some result, so we calculate two
        // distances maxxor and minxor with 0 and then also remove it by doing
        // xor again
        int res = INT_MAX;
        int totalXor = xorResult[0];
        for (int node1 = 1; node1 < n; node1++) {
            for (int node2 = node1 + 1; node2 < n; node2++) {
                 int a, b, c;
                 if (ancestor(node1, node2, timing_in, timing_out)) {
                    // node1 is ancestor of node2
                    a = xorResult[node2];
                    b = xorResult[node1] ^ xorResult[node2];
                    c = totalXor ^ xorResult[node1];
                } else if (ancestor(node2, node1, timing_in, timing_out)) {
                    // node2 is ancestor of node1
                    a = xorResult[node1];
                    b = xorResult[node2] ^ xorResult[node1];
                    c = totalXor ^ xorResult[node2];
                } else {
                    // Disjoint subtrees
                    a = xorResult[node1];
                    b = xorResult[node2];
                    c = totalXor ^ a ^ b;
                }
                int maxXor = max({a, b, c});
                int minXor = min({a, b, c});
                res = min(res, maxXor - minXor);
            }
        }
        return res;
    }
};