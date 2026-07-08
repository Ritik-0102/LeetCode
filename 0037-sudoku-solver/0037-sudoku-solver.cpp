class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        // check for digit in the row
        for(int i=0;i<9;i++){
            if(board[row][i] == dig){
                return false;
            }
        }

        // check for digit in the col
        for(int i=0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        // check for digit in the grid
        int startRowIdx = (row / 3) * 3;
        int startColIdx = (col / 3) * 3;
        for(int i=startRowIdx ; i<=startRowIdx+2 ; i++){
            for(int j=startColIdx ; j<=startColIdx+2 ; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }       
        return true;
    }

    bool helper(vector<vector<char>>& board,int row , int col){
        // Base Case
        if(row == 9){
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the block is not empty
        if(board[row][col] != '.'){
            return helper(board,nextRow,nextCol);
        }

        // Try to place All the Digits
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;
                if(helper(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col] = '.'; // BackTracking
            }    
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};