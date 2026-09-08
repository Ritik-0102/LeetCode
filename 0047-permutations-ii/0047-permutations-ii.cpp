class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& nums,vector<int>& vis,vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i < nums.size();i++){
            // if already visited
            if(vis[i]){
                continue;
            }

            // if the prev element is same , but it is not included in our permutation
            // then it will give duplicate permutation
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]){
                continue;
            }

            // include the element
            vis[i] = 1;
            temp.push_back(nums[i]);

            helper(ans,nums,vis,temp);

            // BackTrack : exclude the element
            vis[i] = 0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> temp;

        sort(nums.begin(),nums.end());

        helper(ans,nums,vis,temp);

        return ans;
    }
};