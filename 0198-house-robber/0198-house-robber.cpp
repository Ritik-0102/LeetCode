class Solution {
public:
    // Memoization DP
    int helper(vector<int>& arr,int idx,vector<int>& dp){
        if(idx >= arr.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        // Not Included the house
        int choice1 = helper(arr,idx+1,dp);
        // Included the house
        int choice2 = arr[idx] + helper(arr,idx+2,dp);

        return dp[idx] = max(choice1,choice2);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n+1,-1);

        return helper(arr,0,dp);
    }
};