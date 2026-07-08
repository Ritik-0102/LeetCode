class Solution {
public:
    void helper(vector<int>& arr, vector<vector<int>>& ans , int idx){
        if(idx == arr.size()){
            ans.push_back({arr});
            return;
        }

        for(int i=idx;i<arr.size();i++){
            swap(arr[i],arr[idx]);
            helper(arr,ans,idx+1);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;

        helper(arr,ans,0);

        return ans;
    }
};