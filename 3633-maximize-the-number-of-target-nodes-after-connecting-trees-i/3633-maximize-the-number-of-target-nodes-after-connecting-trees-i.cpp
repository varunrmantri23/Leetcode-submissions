class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& child, int k) {
        if (k < 0)return 0;
        int res =1;
        for (int neighbor :child[node]) {
            if (neighbor !=parent) {
                res += dfs(neighbor, node, child, k - 1);
            }
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> child(n);
        for (auto& edge : edges1) {
            child[edge[0]].push_back(edge[1]);
            child[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> child2(m);
        for (auto& edge : edges2) {
            child2[edge[0]].push_back(edge[1]);
            child2[edge[1]].push_back(edge[0]);
        }

        vector<int> res1(n);
        for (int i = 0; i < n; i++) {
            res1[i] = dfs(i, -1, child, k);
        }
        int res2 = 0;
        for (int i = 0; i < m; i++) {
            res2 = max(res2, dfs(i, -1, child2, k - 1));
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = res1[i] + res2;
        }
        return res;
    }
};
