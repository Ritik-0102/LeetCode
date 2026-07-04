class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time complexity :- O(m+n)

        // Hence we know that the row & col are both in sorted order
        // we know 0,0 is smallest & n-1,m-1 is largest
        // so we start comparing out target with the top right corner element
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            // If our target is greater than curr element , then we know that we will not get our element in that row (beacuse the curr element is the largest element of that row)
            if(matrix[row][col] < target){
                row++;
            }
            // If our target is smaller than curr element , then we know that we will not get our element in that col (beacuse the curr element is the smallest element of that col)
            else{
                col--;
            }
        }

        return false;
    }
};