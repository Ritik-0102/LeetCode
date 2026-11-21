class Solution {
public:
    int helper(vector<int>& coins,vector<vector<int>>& dp, int amount,int i){
        if(amount == 0){
            return 1;
        }

        if(i < 0 || amount < 0){
            return 0; 
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = helper(coins,dp,amount - coins[i],i);
        int skip = helper(coins,dp,amount,i - 1);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount + 1,-1));

        return helper(coins,dp,amount,n-1);
    }
};