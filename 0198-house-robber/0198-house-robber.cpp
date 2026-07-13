class Solution {
public:
    // Space Optimised DP
    int rob(vector<int>& arr) {
        int n = arr.size();

        if(n==1) return arr[0];

        int prev1 = arr[0];
        int prev2 = max(arr[0],arr[1]);

        int result = prev2;

        for(int i=2;i<n;i++){
            result = max(prev1 + arr[i] , prev2);
            prev1 = prev2;
            prev2 = result;
        }

        return prev2;
    }
};