class Solution {
public:
    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int row,
             int col) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 1 && grid[nrow][ncol] == 1) {
                dfs(vis, grid, nrow, ncol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 1));

        for (int j = 0; j < grid[0].size(); j++) {
            if (vis[0][j] == 1 && grid[0][j] == 1) {
                dfs(vis, grid, 0, j);
            }
            if (vis[grid.size() - 1][j] == 1 && grid[grid.size() - 1][j] == 1) {
                dfs(vis, grid, grid.size() - 1, j);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            if (vis[i][0] == 1 && grid[i][0] == 1) {
                dfs(vis, grid, i, 0);
            }
            if (vis[i][grid[0].size() - 1] == 1 &&
                grid[i][grid[0].size() - 1] == 1) {
                dfs(vis, grid, i, grid[0].size() - 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (vis[i][j] == 1) {
                    sum += grid[i][j];
                }
            }
        }
        return sum;
    }
};