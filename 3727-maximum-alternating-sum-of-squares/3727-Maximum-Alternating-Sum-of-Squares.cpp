class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a) > abs(b);
        });

        int mid = n % 2 == 0 ? n/2 : n/2 + 1;

        for(int i=0;i<mid;i++){
            ans += (nums[i] * nums[i]);
        }

        for(int i=mid;i < n ; i++){
            ans -= (nums[i] * nums[i]);
        }

        return ans;
    }
};