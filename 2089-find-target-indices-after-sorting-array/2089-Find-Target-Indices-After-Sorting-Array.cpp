class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int Count = 0;
        int lessCount = 0;
        vector<int> ans;

        for(int x:nums){
            if(x < target){
                lessCount++;
            }
            else if(x == target){
                Count++;
            }
        }

        while(Count > 0){
            ans.push_back(lessCount++);
            Count--;
        }

        return ans;
    }
};