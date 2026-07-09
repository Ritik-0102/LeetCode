class Solution {
public:
    void helper(vector<int>& arr, int target,int idx ,vector<int>& combination,vector<vector<int>>& ans , set<vector<int>>& s){
        // Base Case - 1
        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back({combination});
                s.insert(combination);
            }            
            return;
        }

        // Base Case - 2
        if(target < 0 || idx == arr.size()){
            return;
        }

        // there are 3 possibilities for every element of array
        // 1. to get included once
        combination.push_back(arr[idx]);
        helper(arr,target - arr[idx], idx + 1, combination , ans , s);
        // 2. to get included many times
        helper(arr,target - arr[idx], idx , combination , ans , s);
        // 3. to get excluded
        combination.pop_back(); // BackTrack
        helper(arr,target, idx + 1, combination , ans , s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        // This helps us to handle duplicate combinations
        set<vector<int>> s;

        helper(candidates,target,0,combination,ans,s);

        return ans;
    }
};