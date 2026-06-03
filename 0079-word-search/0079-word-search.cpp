class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(int row,int col, vector<vector<char>>& board,string word,int idx){
        if(idx == word.size()){
            return true;
        }
        if(row<0||  col<0 || row>=board.size()||col>=board[0].size() || board[row][col]=='$'||board[row][col]!= word[idx] )return false;
        char temp = board[row][col];
        board[row][col]='$';
        
        for(auto &dir:directions){
            int new_i= row+dir[0];
            int new_j = col+ dir[1];

            if(find(new_i,new_j,board,word,idx+1))return true;
        }
        board[row][col]=temp;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m = board[0].size();
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((board[i][j]==word[0])&& find(i,j,board,word,0)){
                    return true;
                }
            }
         }
         return false;
    }
};