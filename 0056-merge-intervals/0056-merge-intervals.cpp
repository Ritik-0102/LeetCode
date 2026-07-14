class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 1){
            return intervals;
        }

        sort(intervals.begin(),intervals.end());

        for(auto i:intervals){
            cout << "[" << i[0] << "," << i[1] << "]  " ;
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
            }
            else{
                int m = ans.size();
                if(ans[m-1][0] == intervals[i][0] && ans[m-1][1] == intervals[i][1]){
                    continue;
                }
                if(ans[m-1][0] < intervals[i][0] && ans[m-1][1] >= intervals[i][1]){
                    continue;
                }
                else if(ans[m-1][0] < intervals[i][1] && ans[m-1][1] >= intervals[i][0]){
                    int newStart = ans[m-1][0];
                    int newEnd = intervals[i][1];
                    ans.pop_back();
                    ans.push_back({newStart,newEnd});
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};