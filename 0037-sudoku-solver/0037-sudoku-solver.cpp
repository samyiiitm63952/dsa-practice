class Solution {
public:

    bool isValid(vector<vector<char>>& board,
                 int row,
                 int col,
                 char ch){

        // check row
        for(int j = 0; j < 9; j++){

            if(board[row][j] == ch){
                return false;
            }
        }

        // check column
        for(int i = 0; i < 9; i++){

            if(board[i][col] == ch){
                return false;
            }
        }

        // check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++){

            for(int j = startCol; j < startCol + 3; j++){

                if(board[i][j] == ch){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i = 0; i < 9; i++){

            for(int j = 0; j < 9; j++){

                // empty cell
                if(board[i][j] == '.'){

                    // try digits
                    for(char ch = '1'; ch <= '9'; ch++){

                        if(isValid(board, i, j, ch)){

                            board[i][j] = ch;

                            // recurse
                            if(solve(board)){
                                return true;
                            }

                            // backtrack
                            board[i][j] = '.';
                        }
                    }

                    // no valid digit possible
                    return false;
                }
            }
        }

        // board completely solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};