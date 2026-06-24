class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = true;

        while (!q.empty()) {
            int ro = q.front().first;
            int co = q.front().second;
            q.pop();

            for (int rdel = -1; rdel <= 1; rdel++) {
                for (int cdel = -1; cdel <= 1; cdel++) {

                    // Skip self and diagonals
                    if (abs(rdel) + abs(cdel) != 1) continue;

                    int nrow = ro + rdel;
                    int ncol = co + cdel;

                    if (nrow < n && ncol < m &&
                        nrow >= 0 && ncol >= 0 &&
                        grid[nrow][ncol] == '1' &&
                        !vis[nrow][ncol]) {

                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        vector<vector<bool>> vis(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );

        int cnt = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return cnt;
    }
};