class Solution {
public:
    int dp[1005][1005];

    bool isPalindrome(const string& s , int i , int j){
        if(i > j){
            return dp[i+1][j+1] = true;
        }

        if(s[i] != s[j]){
            return dp[i+1][j+1] = false;
        }

        if(dp[i+1][j+1] != -1){
            return dp[i+1][j+1];
        }

        return dp[i+1][j+1] = isPalindrome(s,i+1,j-1);
    }

    int countSubstrings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));

        vector<string> ans;
                
        // At least the first character is a palindrome
        int maxLen = 1;
        int start = 0;

        for(int i=0;i<n;i++){
            for(int j = n-1 ; j >= i ; j--){
                if(isPalindrome(s,i,j)){
                    ans.push_back(s.substr(i,j - i + 1));
                }
            }
        }

        return ans.size();
    }
};