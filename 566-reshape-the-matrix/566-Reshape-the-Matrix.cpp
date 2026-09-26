class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        // if the Reshape is not possible
        if((m*n) != (r*c)){
            return mat;
        }

        vector<vector<int>> ans(r,vector<int>(c));

        // Keeps Track of RowIdx & ColIdx to fill data in ans
        int newRow = 0;
        int newCol = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[newRow][newCol] = mat[i][j];

                // Increament Col Idx
                newCol++;

                // If Col Idx comes to end , then reset with zero & increament row Idx
                if(newCol == c){
                    newCol = 0;
                    newRow++;
                }
            }
        }

        return ans;
    }
};