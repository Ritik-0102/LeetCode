class Solution {
public:
    // MultiSoure BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<pair<pair<int,int>,int>> q; // store {{i,j} , time}

        // store all the source nodes for bfs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        // BFS
        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;

            ans = max(ans,time);

            q.pop();

            // now move in all 4 directions from src node
            if(i - 1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == 1){
                q.push({{i-1,j},time + 1});
                vis[i-1][j] = true;
            }
            if(i + 1 < n && vis[i+1][j] == false && grid[i+1][j] == 1){
                q.push({{i+1,j},time + 1});
                vis[i+1][j] = true;
            }
            if(j - 1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == 1){
                q.push({{i,j-1},time + 1});
                vis[i][j-1] = true;
            }
            if(j + 1 < m && vis[i][j+1] == false && grid[i][j+1] == 1){
                q.push({{i,j+1},time + 1});
                vis[i][j+1] = true;
            }
        }

        // check if there is no fresh orange
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    return -1;
                }
            }
        }

        return ans;
    }
};