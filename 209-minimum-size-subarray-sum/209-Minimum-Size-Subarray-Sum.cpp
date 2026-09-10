class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int CurrSum = 0;
        int ans = INT_MAX;
        int left = 0;  // to track starting of our window

        for(int right=0 ; right<n ; right++){
            CurrSum += nums[right];

            // to find absolute minimum length - we shrink our subarray
            while(CurrSum >= target){
                ans = min(ans,right - left + 1);
                CurrSum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};