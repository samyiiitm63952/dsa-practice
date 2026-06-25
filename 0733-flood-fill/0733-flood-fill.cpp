class Solution {
public:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int row,
             int col, int newcolor, int oldrang) {
        ans[row][col] = newcolor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                image[nrow][ncol] == oldrang && ans[nrow][ncol] != newcolor) {
                dfs(ans, image, nrow, ncol, newcolor, oldrang);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int oldrang = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(ans, image, sr, sc, color, oldrang);
        return ans;
    }
};