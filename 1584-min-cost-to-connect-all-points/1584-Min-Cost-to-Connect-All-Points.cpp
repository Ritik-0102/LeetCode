class Solution {
public:
    int manhattanDist(vector<vector<int>>& points,int i,int j){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's Algorithm
        int n = points.size();

        vector<bool> mstSet(n,false);
        int mstCost = 0;

        // store {wt,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(pq.size() > 0){
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(mstSet[node]){
                continue;
            }

            mstCost += wt;
            mstSet[node] = true;

            for(int i=0;i<n;i++){
                if(!mstSet[i]){
                    int dist = manhattanDist(points,node,i);
                    pq.push({dist,i});
                }
            }
        }

        return mstCost;
    }
};