class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        // Sort by starting points
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        // Push the first interval to start the comparison
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // ans.back() gives us direct access to the last merged interval
            // If the current interval overlaps with the last one in 'ans'
            if (ans.back()[1] >= intervals[i][0]) {
                // Merge them by updating the end time of the last interval in 'ans'
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // No overlap, so we safely add it to our answer
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};