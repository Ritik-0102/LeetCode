class Solution {
public:
    int helper(vector<int>& rods,int idx,int diff,vector<vector<int>>& dp){
        if(idx == rods.size()){
            return diff == 0 ? 0 : INT_MIN;
        }

        if(dp[idx][diff] != -1){
            return dp[idx][diff];
        }

        // Option 1 : skip the rod
        int skip = helper(rods,idx+1,diff,dp);

        // Option 2 : Add rod to the taller support
        int taller = rods[idx] + helper(rods,idx+1,diff + rods[idx] , dp);

        // Option 3 : Add rod to the shorter support
        int added_height = max(0,(rods[idx] - diff));
        int shorter = added_height + helper(rods,idx+1,abs(rods[idx] - diff),dp);

        return dp[idx][diff] = max({skip,taller,shorter});
    }

    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(20,vector<int>(5005,-1));

        return helper(rods,0,0,dp);
    }
};