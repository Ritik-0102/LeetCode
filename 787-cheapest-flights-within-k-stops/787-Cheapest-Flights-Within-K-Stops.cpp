class Solution {
public:
    // Modified BFS
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // graph[i] has dynamic vector of edges
        vector<pair<int,int>> graph[n];

        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v,wt});
        }

        // Store { Node , {Cost , stops}
        queue<pair<int,pair<int,int>>> q;
        vector<int> price(n,INT_MAX);

        q.push({src,{0,-1}});
        price[src] = 0;

        while(q.size() > 0){
            int u = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;

            q.pop();

            for(auto& edge:graph[u]){
                int v = edge.first;
                int wt = edge.second;

                // Edge Relaxation && stops < k
                if((price[v] > cost + wt) && (stops + 1 <= k)){
                    price[v] = cost + wt;
                    q.push({v,{price[v],stops+1}});
                }
            }
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};