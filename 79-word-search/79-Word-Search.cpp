class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,int idx,int i,int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]){
            return false;
        }

        if(idx == word.size() - 1){
            return true;
        }

        char temp = board[i][j];
        // Mark as Visited
        board[i][j] = '#';

        idx++;

        bool found = dfs(board,word,idx,i+1,j) || dfs(board,word,idx,i-1,j) || dfs(board,word,idx,i,j+1) || dfs(board,word,idx,i,j-1);

        // BackTrack : Restore the value
        board[i][j] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && dfs(board,word,0,i,j)){
                    return true;
                }
            }
        }

        return false;
    }
};