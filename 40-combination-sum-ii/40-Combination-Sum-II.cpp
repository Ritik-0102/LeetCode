class Solution {
public:
    void helper(vector<int>& candidates, int target,int idx,vector<int>& temp,vector<vector<int>>& ans){
        // Base case: If target becomes 0, we found a valid combination
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        // Base case: We've exhausted the array.
        if(idx == candidates.size()){
            return;
        }

        for(int i=idx ; i < candidates.size(); i++){
            // Skip Duplicates
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }

            // 1. Choose the current candidate
            temp.push_back(candidates[i]);

            // 2. Explore further (pass i + 1 because we cannot reuse the same element)
            helper(candidates,target - candidates[i],i+1,temp,ans);

            // 3. Backtrack (remove the chosen element to try the next one in the loop)
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(),candidates.end());

        helper(candidates,target,0,temp,ans);

        return ans;
    }
};