class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjls, vector<bool>& vis,
             int& nodes, int& edges) {
        
        vis[node] = true;
        nodes++;
        edges += adjls[node].size();

        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, adjls, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjls(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeCount = 0;

                dfs(i, adjls, vis, nodes, edgeCount);
                edgeCount /= 2;

                int required = nodes * (nodes - 1) / 2;

                if (edgeCount == required) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};