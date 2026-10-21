class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;

        sort(begin(points),end(points));
    
        for(int i=1;i<n;i++){
            if(points[i-1][1] < points[i][0]){
                ans++;
            }
            else if(points[i-1][1] < points[i][1] ){
                points[i][1] = points[i-1][1];
            }
        }

        return ans;
    }
};