class Solution {
public:
    // Sliding Window :-
    // Instead of calculating 1s inside our window , we keep track of zero's inside our window 
    // to check how many flips we have made (0 -> 1)
    
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        int left = 0;
        int zeroCount = 0;
        
        for(int right = 0;right < n ; right++){
            if(nums[right] == 0){
                zeroCount++;
            }

            // if zero count is greater than k , then we need to shrink our window
            while(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }

            int currLength = right - left + 1;
            ans = max(ans,currLength);
        }

        return ans;
    }
};