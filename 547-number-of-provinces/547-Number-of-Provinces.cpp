class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<bool>& vis){
        vis[i] = true;

        for(int j=0;j<adj.size();j++){
            if(adj[i][j] == 1 && !vis[j]){
                dfs(j,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int ans = 0;
        vector<bool> vis(adj.size(),false);

        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }

        return ans;
    }
};