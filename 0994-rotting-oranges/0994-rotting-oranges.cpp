class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int,int>,int>> q;

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    int fresh = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2)
                q.push({{i,j},0});
            else if(grid[i][j] == 1)
                fresh++;
        }
    }

    int time = 0;
    int rotten = 0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        int row = node.first.first;
        int col = node.first.second;
        int t = node.second;

        time = max(time,t);

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 &&
               nrow<n && ncol<m &&
               grid[nrow][ncol]==1)
            {
                grid[nrow][ncol] = 2;
                rotten++;
                q.push({{nrow,ncol},t+1});
            }
        }
    }

    if(rotten != fresh) return -1;
    return time;
}
};