class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[1005][1005];

        memset(dp,0,sizeof(dp));

        for(int i=n-1 ; i >= 0 ; i--){
            dp[i][i] = 1;

            for(int j = i+1 ; j < n ; j++){
                if(s[i] == s[j]){
                    // Match found: add 2 to the inner sequence length
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    // No match: take the max of excluding the left or right character
                    dp[i][j] = max( dp[i+1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};