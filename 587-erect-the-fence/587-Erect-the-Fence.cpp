class Solution {
public:
    int FindEquationValue(pair<int,int> P1,pair<int,int>& P2,pair<int,int>& P3){
        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;

        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;

        // For Lower is should be greater than 0
        // For Upper is should be lesser than 0
        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees),end(trees));

        vector<vector<int>> ans;

        deque<pair<int,int>> lower;    
        deque<pair<int,int>> upper;

        for(auto& point : trees){
            int l = lower.size();
            int u = upper.size();

            while(l >= 2 && FindEquationValue({point[0],point[1]},lower[l-1],lower[l-2]) < 0){
                l--;
                lower.pop_back();
            }
            while(u >= 2 && FindEquationValue({point[0],point[1]},upper[u-1],upper[u-2]) > 0){
                u--;
                upper.pop_back();
            }

            upper.push_back({point[0],point[1]});
            lower.push_back({point[0],point[1]});
        }    

        set<pair<int,int>> s;

        for(auto& point:lower){
            s.insert(point);
        }
        for(auto& point:upper){
            s.insert(point);
        }

        for(auto& point:s){
            ans.push_back({point.first,point.second});
        }

        return ans;
    }
};