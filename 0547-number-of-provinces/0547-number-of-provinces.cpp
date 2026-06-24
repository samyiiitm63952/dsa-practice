class Solution {
public:
    void dfs(vector<int>& vis, vector<vector<int>>& adjls, int start) {
        vis[start] = 1;

        for (auto it : adjls[start]) {
            if (vis[it] == 0) {
                dfs(vis, adjls, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // adjacency list
        vector<vector<int>> adjls(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(vis, adjls, i);
            }
        }

        return cnt;
    }
};