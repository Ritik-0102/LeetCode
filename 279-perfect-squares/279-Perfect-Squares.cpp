class Solution {
public:
    int numSquares(int n) {
        // intialize our dp with (n+1) our max possible ans (choosing all 1s)
        vector<int> dp(n+1,n+1);

        dp[0] = 0;

        for(int i=0;i<=n;i++){
            // Try all perfect squares for a number
            for(int j=1;(j*j) <= i;j++){
                int square = j*j;

                // we take min of what we already have &
                // 1 (for curr square) + best answer for our remainder
                dp[i] = min(dp[i],dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};