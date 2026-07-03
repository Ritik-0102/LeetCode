class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // We are using Binary search Two Times :-

        // 1. to find row in which our target can be
        // 2. to find our target in that row
        
        int start = 0;
        int end = matrix.size() - 1;

        while(start <= end){
            int mid_row = start + (end - start)/2;

            int curr_size = matrix[mid_row].size();
            if(matrix[mid_row][0] <= target && matrix[mid_row][curr_size-1] >= target ){
                int left = 0;
                int right = curr_size - 1;

                while(left <= right){
                    int mid_col = left + (right - left)/2;
                    if(matrix[mid_row][mid_col] == target){
                        return true;
                    }
                    if(matrix[mid_row][mid_col] < target){
                        left = mid_col + 1;
                    }
                    else{
                        right = mid_col - 1;
                    }
                }
            }

            if(matrix[mid_row][0] < target){
                start = mid_row + 1;
            }
            else{
                end = mid_row - 1;
            }
        }

        return false;
    }
};