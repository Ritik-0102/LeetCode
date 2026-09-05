class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;

        int n = nums.size();

        vector<int> minArray(n);

        for(int i=n-1;i>=0;i--){
            minimum = min(minimum,nums[i]);
            minArray[i] = minimum;
        }

        for(int i=0;i<n;i++){
            maximum = max(maximum,nums[i]);
            int score = maximum - minArray[i];

            if(score <= k){
                return i;
            }
        }

        return -1;
    }
};