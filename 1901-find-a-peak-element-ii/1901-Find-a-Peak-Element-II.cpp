class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 1. Find the row with the maximum element in the current mid column
            int max_row = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[max_row][mid]) {
                    max_row = i;
                }
            }
            
            // 2. Check left and right neighbors safely using boundary conditions
            bool is_left_smaller = (mid == 0) || (mat[max_row][mid] > mat[max_row][mid - 1]);
            bool is_right_smaller = (mid == n - 1) || (mat[max_row][mid] > mat[max_row][mid + 1]);
            
            // 3. Decide where to search next
            if (is_left_smaller && is_right_smaller) {
                // Peak found
                return {max_row, mid};
            }
            else if (!is_right_smaller) {
                // Right neighbor is larger, search right half
                left = mid + 1;
            }
            else {
                // Left neighbor is larger, search left half
                right = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};