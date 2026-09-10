class Solution {
public:
    bool isSafe(vector<string>& board , int row , int col){
        int n = board.size();
        // Check queen safety in row
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        // Check queen safety in column
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // Check queen safety in left diagonal
        for(int i=row , j = col ; i>=0 && j>=0 ; i-- , j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // Check queen safety in right diagonal
        for(int i=row , j=col ; i>=0 && j<n ; i-- , j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    void helper(vector<vector<string>>& ans,int n,vector<string>& board , int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        // check for the placements of queen in a row 
        for(int i=0;i<n;i++){
            if(isSafe(board,row,i)){
                board[row][i] = 'Q';
                helper(ans,n,board,row+1);
                board[row][i] = '.'; // BackTracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n,string(n,'.'));

        // we will check for correct place for our queen Row wise
        helper(ans,n,board,0);

        return ans;
    }
};