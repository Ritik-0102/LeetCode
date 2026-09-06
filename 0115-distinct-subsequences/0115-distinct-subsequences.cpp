class Solution {
public:
    int helper(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        // if j reached the end , then we found match
        if(j < 0){
            return 1;
        }

        // if i reached the end , but the j didn't , then match not found
        if(i < 0){
            return 0;
        }

        // Already Calculated
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long long matches;

        if(s[i] == t[j]){
            // option 1: include ith character from s
            // option 2: exclude ith character from s
            matches = (long long)helper(s,t,i-1,j-1,dp) + (long long)helper(s,t,i-1,j,dp);
        }
        else{
            // we can't choose ith character
            matches = (long long)helper(s,t,i-1,j,dp);
        }

        dp[i][j] = (int)matches;
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m > n){
            return 0;
        }

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return helper(s,t,n-1,m-1,dp);
    }
};