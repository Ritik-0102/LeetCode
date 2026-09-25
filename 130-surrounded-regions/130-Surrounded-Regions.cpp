class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int row, int col) {
        // 1. Check bounds: row must be 0 to rows-1, col must be 0 to cols-1
        // 2. Stop if cell is already visited
        // 3. Stop if cell is 'X' (we only care about connecting 'O's)
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || vis[row][col] == true || board[row][col] == 'X') {
            return;
        }

        // Mark the current 'O' as visited (meaning it's connected to the boundary and safe)
        vis[row][col] = true;

        // Recursively check all 4 adjacent directions for connected 'O's
        dfs(board, vis, row, col + 1); // Right
        dfs(board, vis, row, col - 1); // Left
        dfs(board, vis, row + 1, col); // Down
        dfs(board, vis, row - 1, col); // Up
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; // Edge case: empty board
        
        int rows = board.size();       // Number of rows (m)
        int cols = board[0].size();    // Number of columns (n)

        // Initialize visited matrix specifically to match the rows x cols dimensions
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // Traverse Top and Bottom boundaries (Rows 0 and rows-1)
        for (int j = 0; j < cols; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(board, vis, 0, j);
            }
            if (!vis[rows - 1][j] && board[rows - 1][j] == 'O') {
                dfs(board, vis, rows - 1, j);
            }
        }

        // Traverse Left and Right boundaries (Cols 0 and cols-1)
        for (int i = 0; i < rows; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(board, vis, i, 0);
            }
            if (!vis[i][cols - 1] && board[i][cols - 1] == 'O') {
                dfs(board, vis, i, cols - 1);
            }
        }

        // Final sweep: Flip any 'O' that wasn't reached by our boundary DFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If it is 'O' but NOT visited, it is completely surrounded
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};