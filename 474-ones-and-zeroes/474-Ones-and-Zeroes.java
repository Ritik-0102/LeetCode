class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int dp[][] = new int[m+1][n+1];

        for(String s:strs){
            
            int Zeroes = 0;
            for(int k = 0 ; k < s.length() ; k++){
                if(s.charAt(k) == '0'){
                    Zeroes++;
                }
            }
            int Ones = s.length() - Zeroes;

            for(int i = m ; i >= Zeroes ; i--){
                for(int j = n ; j >= Ones ; j--){
                    dp[i][j] = Math.max(dp[i][j] , dp[i - Zeroes][j - Ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
}