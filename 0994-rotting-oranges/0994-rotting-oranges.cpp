class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> start;
        queue<pair<pair<int, int>, int>> q;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    start.push_back({i, j});
                }
            }
        }
        int time = 0;
        for (auto it : start) {
            q.push({it, time});
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front().first;
                int curtime = q.front().second;

                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = curr.first + delrow[i];
                    int ncol = curr.second + delcol[i];

                    if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                        ncol < grid[0].size() && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, curtime+1});
                    }
                }
                time = max(curtime, time);
            }
        }

        for (auto row : grid) {
            for (auto col : row) {
                if (col == 1)
                    return -1;
            }
        }
        return time;
    }
};