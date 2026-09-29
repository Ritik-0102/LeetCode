class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));

        sort(sources.begin(),sources.end(),[](const vector<int>& a,const vector<int>& b){
            return a[2] > b[2];
        });

        queue<pair<int,int>> q;

        // Multi Source BFS
        for(int i=0;i<sources.size();i++){
            int r = sources[i][0];
            int c = sources[i][1];
            int Color = sources[i][2];

            // If grid is already colored with greater value , then no need to do BFS
            if(grid[r][c] >= Color){
                continue;
            }

            q.push({r,c});
            grid[r][c] = Color;

        }

        // BFS
        int Row_Move[] = {-1,1,0,0};
        int Col_Move[] = {0,0,-1,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int Color = grid[x][y];
            q.pop();

            // Try All possible directions
            for(int i = 0 ; i < 4 ; i++){
                int next_X = x + Row_Move[i];
                int next_Y = y + Col_Move[i];

                // Check whether it is valid cell
                // And check whether the next cell should not be coloured yet
                if(next_X >= 0 && next_X < n && next_Y >= 0 && next_Y < m && grid[next_X][next_Y] == 0){
                    // Fill only if it has lesse value than Color
                    if(grid[next_X][next_Y] < Color){
                        grid[next_X][next_Y] = Color;
                        q.push({next_X,next_Y});
                    }
                }
            }
        }

        return grid;
    }
};