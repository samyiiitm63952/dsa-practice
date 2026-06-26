class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> safe(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                safe[0][j] = true;
            }
        }
        for (int i = 1; i < n; i++) {
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                safe[i][m - 1] = true;
            }
        }
        for (int j = m - 2; j >= 0 && n > 1; j--) {
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                safe[n - 1][j] = true;
            }
        }
        for (int i = n - 2; i > 0 && m > 1; i--) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                safe[i][0] = true;
            }
        }

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int ro = q.front().first;
            int co = q.front().second;

            q.pop();

            for(int i =0;i<4;i++){
                int nro = ro +delrow[i];
                int nco = co + delcol[i];

                if(nro>=0 && nco>=0 && nro <n && nco <m && board[nro][nco]=='O' && !safe[nro][nco]){
                    safe[nro][nco]= true;
                    q.push({nro,nco});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] =='O' && !safe[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};