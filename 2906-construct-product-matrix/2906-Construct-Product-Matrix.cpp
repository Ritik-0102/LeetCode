class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n,vector<int>(m));

        // 1st Pass - top left to bottom right (Calculate Prefix products)
        long long Prefix = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = Prefix;
                Prefix = (Prefix * grid[i][j]) % 12345;
            }
        }
        
        // 2nd Pass - bottom right To top left(Calculate Suffix products)
        long long Suffix = 1;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                ans[i][j] = (ans[i][j] * Suffix) % 12345;
                Suffix = (Suffix * grid[i][j]) % 12345;
            }
        }

        return ans;
    }
};