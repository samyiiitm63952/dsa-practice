class Solution {
public:
   int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1e9)));
        
        dp[0][0][0] = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = grid[i][j];
                int cost = (val == 0 ? 0 : 1);
                
                for(int c = 0; c <= k; c++) {
                    if(c - cost < 0) continue;
                    
                    if(i == 0 && j == 0) continue;
                    
                    int best = -1e9;
                    
                    if(i > 0)
                        best = max(best, dp[i-1][j][c - cost]);
                    
                    if(j > 0)
                        best = max(best, dp[i][j-1][c - cost]);
                    
                    if(best > -1e9)
                        dp[i][j][c] = best + val;
                }
            }
        }
        
        int ans = -1;
        for(int c = 0; c <= k; c++)
            ans = max(ans, dp[m-1][n-1][c]);
        
        return ans < 0 ? -1 : ans;
    }
};