class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        

        double avg = sum / k;
        for(int i=1;i<=n-k;i++){
            sum -= nums[i-1];
            sum += nums[i+k-1];

            avg = max(avg,sum/k);
        }

        return avg;
    }
};