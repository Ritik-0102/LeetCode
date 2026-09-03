class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int c = 1;

        if(nums[0] == 1){
            ans = 1;
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i] == 1){
                if(nums[i-1] == nums[i]){
                    c++;
                }
                ans = max(c,ans);
            }
            else{
                c = 1;
            }
        }

        return ans;
    }
};