class Solution {
public:
    int getDistance(int x,int y){
        return (x * x) + (y * y);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = -((x * x) + (y * y));

            pq.push({dist,{points[i][0],points[i][1]}});
        }

        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};