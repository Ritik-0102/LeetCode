class Solution {
public:
    int helper(vector<int>& nums,int idx,int prev,vector<vector<int>>& dp){
        if(idx >= nums.size()){
            return 0;
        }

        // Because the previous is initialized as -1 ,so we are accessing dp[idx][prev + 1]
        if(dp[idx][prev + 1] != -1){
            return dp[idx][prev + 1];
        }

        int pick = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
            pick = 1 + helper(nums,idx+1,idx,dp);
        }

        int not_pick = helper(nums,idx+1,prev,dp);

        return dp[idx][prev + 1] = max(pick,not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return helper(nums,0,-1,dp);
    }
};