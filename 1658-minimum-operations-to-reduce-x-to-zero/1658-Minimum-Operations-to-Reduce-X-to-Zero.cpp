class Solution {
public:
    // we will use inverse technique 
    // we try to find max size of elements window present after removal of elements

    // using Sliding Window Technique

    int minOperations(vector<int>& nums, int x) {
        int sum = 0;

        for(int i:nums){
            sum += i;
        }

        // Target sum of window of middle elements
        int target = sum - x;

        // Base Case 1: if target is less than 0 , it is not possible to reduce X
        if(target < 0){
            return -1;
        }

        // Base Case 2: if target is equal to 0 , then we need to remove all elements
        if(target == 0){
            return nums.size();
        }

        int ans = 0;
        int left = 0;
        int currSum = 0;

        for(int right = 0; right < nums.size() ;right++){
            currSum += nums[right];

            // shrink window size
            while(currSum > target){
                currSum -= nums[left];
                left++;
            }

            if(target == currSum){
                ans = max(ans,right - left + 1);
            }
        }

        return ans == 0 ? -1 : nums.size() - ans;
    }
};