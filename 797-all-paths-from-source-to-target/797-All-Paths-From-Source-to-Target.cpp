class Solution {
public:
    void dfs(int u,vector<vector<int>>& graph,vector<int>& temp,vector<vector<int>>& ans){
        if(u == graph.size() - 1){
            ans.push_back(temp);
            return;
        }

        for(int v : graph[u]){
            temp.push_back(v);
            dfs(v,graph,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        temp.push_back(0);

        dfs(0,graph,temp,ans);

        return ans;
    }
};