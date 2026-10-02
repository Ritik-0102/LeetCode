class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left)/2;
            
            // It is Increasing Slope , means we have peak on right side
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }
            // It is Decreasing Slope , means we have peak on left side (Or mid could be the Peak)
            else{
                right = mid;
            }
        }

        // When left == right, we have narrowed down to a single peak element
        return left;
    }
};