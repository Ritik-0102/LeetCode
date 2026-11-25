class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];

        int counter = 1;

        int up = 0;
        int low = n - 1;
        int left = 0;
        int right = n - 1;

        while(up <= low && left <= right){

            for(int i = left ; i <= right ; i++){
                ans[up][i] = counter;
                counter++;
            }
            up++;

            for(int i = up ; i <= low ; i++){
                ans[i][right] = counter;
                counter++;
            }
            right--;

            if(up > low || left > right){
                break;
            }

            for(int i = right ; i >= left ; i--){
                ans[low][i] = counter;
                counter++;
            }
            low--;

            for(int i = low ; i >= up ; i--){
                ans[i][left] = counter;
                counter++;
            }
            left++;
        }

        return ans;
    }
}