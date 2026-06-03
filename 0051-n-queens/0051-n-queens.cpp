class Solution {
public:
    bool isafe(vector<string>board,int n,int row, int col){
        for(int r=row,c=col;r>=0&&c>=0;r--,c--){
            if(board[r][c]=='Q')return false;
        }
        for(int r=row,c=col;r>=0&&c>=0;c--){
            if(board[r][c]=='Q')return false;
        }
        for(int r=row,c=col;r<n&&c>=0;r++,c--){
            if(board[r][c]=='Q')return false;
        }
        return true;
    }

    void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isafe(board,n,row,col)){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
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
        solve(0,ans,board,n);
        return ans;
    }
};