class Solution {
public:
    // Patience Sorting - O(nlogn)

    // It finds the index of the FIRST element in LIS that is >= x
    int helper(vector<int>& LIS,int x){
        int left = 0;
        int right = LIS.size()-1;

        while(left < right){
            int mid = left + (right - left)/2;

            // If mid element is greater than or equal to x, 
            // the answer is either at mid or to the left of mid.
            if(LIS[mid] >= x){
                right = mid;
            }
            // If mid element is strictly less than x,
            // the answer must be strictly to the right of mid.
            else{
                left = mid + 1;
            }
        }

        return left;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for(int i:nums){
            // Case 1: LIS is empty OR current number is strictly greater than 
            // the last element in LIS. This means we can extend our longest sequence.
            if(LIS.empty() || LIS.back() < i){
                LIS.push_back(i);
            }
            // Case 2: Current number is smaller than or equal to the last element.
            // We use binary search to find the correct spot to overwrite.
            else{
                int idx = helper(LIS,i);

                // By replacing a larger number with a smaller one (i), 
                // we don't increase the length, but we create a "better" 
                // foundation for future numbers to attach to.
                LIS[idx] = i;
            }
        }

        // The size of the LIS array represents the length of the 
        // longest increasing subsequence found.
        return LIS.size();
    }
};