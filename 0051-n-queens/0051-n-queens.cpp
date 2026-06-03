class Solution {
public:
    void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n,vector<int>& lr,vector<int>& upd, vector<int>& lrd){
        if(col==n){
            ans.push_back(board); 
            return;
        }
        for(int row = 0;row<n;row++){
            if(lr[row]==0 && upd[n-1 +col-row]==0 && lrd[col+row]==0){
                lr[row]=1;
                upd[n-1 +col-row]=1;
                lrd[row +col]=1;
                board[row][col]='Q';
                solve(col+1,ans,board,n,lr,upd,lrd);
                lr[row]=0;
                upd[n-1 +col-row]=0;
                lrd[row +col]=0;
                board[row][col]='.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(auto &it:board){
            it=s;
        }
        vector<int>lr(n,0),upd(2*n-1,0),lrd(2*n-1,0);
        solve(0,ans,board,n,lr,upd,lrd);
        return ans;
    }
};