class Solution {
public:
    bool helper(vector<vector<int>>& grid,int row,int col, int n , int expectedValue){
        if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != expectedValue){
            return false;
        }
        if(grid[row][col] == (n*n) - 1){
            return true;
        }

        bool path1 = helper(grid,row+2,col+1,n,expectedValue + 1);
        bool path2 = helper(grid,row+2,col-1,n,expectedValue + 1);
        bool path3 = helper(grid,row-2,col+1,n,expectedValue + 1);
        bool path4 = helper(grid,row-2,col-1,n,expectedValue + 1);
        bool path5 = helper(grid,row+1,col+2,n,expectedValue + 1);
        bool path6 = helper(grid,row-1,col+2,n,expectedValue + 1);
        bool path7 = helper(grid,row+1,col-2,n,expectedValue + 1);
        bool path8 = helper(grid,row-1,col-2,n,expectedValue + 1);

        return path1 || path2 || path3 || path4 || path5 || path6 || path7 || path8 ;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid,0,0,n,0);
    }
};