class Solution {
public:
    int helper(vector<int>& coins,vector<vector<int>>& dp, int amount,int i){
        if(amount == 0){
            return 0;
        }

        if(i < 0 || amount < 0){
            return 1e9; 
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = 1 + helper(coins,dp,amount - coins[i],i);
        int skip = helper(coins,dp,amount,i - 1);

        return dp[i][amount] = min(take,skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));

        int ans = helper(coins,dp,amount,n-1);

        return ans == 1e9 ? -1 : ans;
    }
};