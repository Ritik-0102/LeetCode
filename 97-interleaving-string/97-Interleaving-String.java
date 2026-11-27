class Solution {
    int dp[][] = new int[101][101];

    boolean helper(String s1,String s2,String s3,int i,int j){
        if(i == s1.length() && j == s2.length()){
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j] == 1;
        }

        int k = i + j;
        boolean ans = false;

        if(i < s1.length() && s1.charAt(i) == s3.charAt(k)){
            if(helper(s1,s2,s3,i+1,j)){
                ans = true;
            }
        }

        if(!ans && j < s2.length() && s2.charAt(j) == s3.charAt(k)){
            if(helper(s1,s2,s3,i,j+1)){
                ans = true;
            }
        }

        dp[i][j] = ans == true ? 1 : 0;
        return ans;
    }

    public boolean isInterleave(String s1, String s2, String s3) {   
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        
        for(int row[]:dp){
            Arrays.fill(row,-1);
        }            

        return helper(s1,s2,s3,0,0);
    }
}