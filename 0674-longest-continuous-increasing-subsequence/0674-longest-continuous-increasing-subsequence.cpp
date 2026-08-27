class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int c = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                c++;
                ans = max(ans,c);
            }
            else{
                c = 1;
            }
        }

        return ans;
    }
};