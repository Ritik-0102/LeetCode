class Solution {
public:
    bool Penalty(vector<int>& nums,int mid, int maxOperations){
        long long operations = 0;
        
        for(int balls : nums){
            if (balls > mid) {
                // Number of splits needed for this specific bag
                operations += (balls - 1) / mid;
            }
        }
        
        return operations <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        // Minimum Possible balls
        int left = 1; 

        // Maximum Possible balls in a bag -> higgest balls in bag
        int right = 0;
        for(int i:nums){
            right = max(right,i);
        }
        
        int ans = right;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(Penalty(nums,mid,maxOperations)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};