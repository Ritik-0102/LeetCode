class Solution {
    int[] dp = new int[20];

    int helper(int n){
        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;

        for(int root = 1; root <= n ; root++){
            int leftWays = helper(root - 1);
            int rightWays = helper(n - root);

            ans += (leftWays * rightWays);
        }
        
        return dp[n] = ans;
    }

    public int numTrees(int n) {
        Arrays.fill(dp,-1);

        return helper(n);
    }
}