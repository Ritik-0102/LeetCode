class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;

        int ans[][] = new int[n+1][2];

        int i = 0;
        int j = 0;

        // 1. Add all intervals that end before newInterval starts
        while(i < n && intervals[i][1] < newInterval[0]){
            ans[j] = intervals[i];
            i++;
            j++;
        }

        // 2. Merge all overlapping intervals with newInterval
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = Math.min(intervals[i][0],newInterval[0]);
            newInterval[1] = Math.max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans[j] = newInterval;
        j++;

        // 3. Add all remaining intervals
        while(i < n){
            ans[j] = intervals[i];
            i++;
            j++;
        }

        // trim unused trailing [0, 0] slots
        return Arrays.copyOf(ans, j);
    }
}