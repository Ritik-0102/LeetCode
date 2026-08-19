class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int color, int par){
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == par && grid[i][j] != color){
            grid[i][j] = color;

            dfs(grid,i+1,j,color,par);
            dfs(grid,i-1,j,color,par);
            dfs(grid,i,j+1,color,par);
            dfs(grid,i,j-1,color,par);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);

        return image;
    }
};