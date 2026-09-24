class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_set<int> RowsWithZero;
        unordered_set<int> ColWithZero;

        for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    RowsWithZero.insert(i);
                    ColWithZero.insert(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j = 0 ; j < m ; j++){
                if(RowsWithZero.find(i) != RowsWithZero.end() || ColWithZero.find(j) != ColWithZero.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};