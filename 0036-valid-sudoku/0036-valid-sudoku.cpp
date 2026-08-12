class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col] == board[row][col] && row != i){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i] == board[row][col] && col != i){
                return false;
            }
        }

        int startRowIdx = (row / 3) * 3;
        int startColIdx = (col / 3) * 3;
        for(int i=startRowIdx;i<=startRowIdx+2;i++){
            for(int j=startColIdx;j<=startColIdx+2;j++){
                if(board[i][j] == board[row][col] && (row != i || col != j)){
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.' && isValid(board,i,j) == false){
                    return false;
                }
            }
        }

        return true;
    }
};