class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjls, vector<bool>& vis) {
        vis[node] = true;

        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, adjls, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;

        vector<vector<int>> adjls(total);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // Build adjacency list
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int node = i * cols + j;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        if (ni >= 0 && ni < rows &&
                            nj >= 0 && nj < cols &&
                            grid[ni][nj] == '1') {

                            int neighbor = ni * cols + nj;
                            adjls[node].push_back(neighbor);
                        }
                    }
                }
            }
        }

        vector<bool> vis(total, false);
        int cnt = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int node = i * cols + j;

                if (grid[i][j] == '1' && !vis[node]) {
                    cnt++;
                    dfs(node, adjls, vis);
                }
            }
        }

        return cnt;
    }
};