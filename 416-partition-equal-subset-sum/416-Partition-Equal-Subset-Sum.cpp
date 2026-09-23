class Solution {
public:
    bool helper(vector<int>& arr,int idx,int sum,vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }

        if(idx == arr.size() || sum < 0){
            return false;
        }

        if(dp[idx][sum] != -1){
            return dp[idx][sum] == 1;
        }

        bool include = helper(arr,idx+1,sum - arr[idx],dp);
        bool exclude = helper(arr,idx+1,sum,dp);

        bool result = include || exclude;
        dp[idx][sum] = result ? 1 : 0;

        return result;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i:nums){
            sum += i;
        }

        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return helper(nums,0,target,dp);
    }
};