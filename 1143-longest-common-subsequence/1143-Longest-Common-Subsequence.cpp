class Solution {
public:
    int helper(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        if(j < 0 || i < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int pick = 0;
        int not_pick1 = 0;
        int not_pick2 = 0;

        if(s[i] == t[j]){
            pick = 1 + helper(s,t,i-1,j-1,dp);
        }
        else{
            not_pick1 = helper(s,t,i-1,j,dp);
            not_pick2 = helper(s,t,i,j-1,dp);
        }

        return dp[i][j] = max({pick,not_pick1,not_pick2});
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return helper(text1,text2,n-1,m-1,dp);
    }
};