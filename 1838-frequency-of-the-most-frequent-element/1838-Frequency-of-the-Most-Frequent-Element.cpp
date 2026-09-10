class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int freq = 0;
        int l = 0;
        long long CurrSum = 0;

        for(int r=0 ; r < nums.size() ; r++){
            CurrSum += nums[r];

            long long window_len = r - l + 1;
            long long costOfOperations = ((long long)nums[r] * window_len) - CurrSum;

            while(costOfOperations > k){
                CurrSum -= nums[l];
                l++;

                window_len = r - l + 1;
                costOfOperations = ((long long)nums[r] * window_len) - CurrSum;
            }

            freq = max(freq,(int)window_len);
        }

        return freq;
    }
};