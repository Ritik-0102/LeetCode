class Solution {
    int dp[][] = new int[21][1001];

    int helper(int arr[],int idx,int target){
        if(idx == 0 && target == 0){
            return 1;
        }

        if(idx == 0 || target < 0){
            return 0;
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int include = helper(arr,idx - 1,target - arr[idx - 1]);
        int exclude = helper(arr,idx - 1,target);

        return dp[idx][target] = include + exclude;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        for(int[] row : dp){
            Arrays.fill(row,-1);
        }

        int sum = 0;
        for(int i:nums){
            sum += i;
        }

        target = Math.abs(target);

        if((sum + target) % 2 != 0){
            return 0;
        }

        int s1 = (sum + target) / 2;
        return helper(nums,n,s1);
    }
}