class Solution {
public:
    void helper(vector<int>& arr,vector<vector<int>>& ans,int idx, vector<int>& subset){
        if(idx == arr.size()){
            ans.push_back(subset);
            return;
        }

        // There are two choices for every element of array
        // 1. to get included in subset
        subset.push_back(arr[idx]);
        helper(arr,ans,idx+1,subset);
        // While BackTracking we need to remove the element also
        subset.pop_back();

        // To Handle the duplicate elements
        int i = idx + 1;
        while(i < arr.size()  && arr[i] == arr[i-1]){
            i++;
        }

        // 2. to get excluded from subset
        helper(arr,ans,i,subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans ;
        vector<int> subset;

        // Sort the array so that we can handle duplicate easily
        sort(arr.begin(),arr.end());

        helper(arr,ans,0,subset);

        return ans;
    }
};