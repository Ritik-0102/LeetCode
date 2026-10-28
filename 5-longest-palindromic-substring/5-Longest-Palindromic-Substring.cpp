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

    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
                
        string longest = s.substr(0, 1); // At least the first character is a palindrome

        for(int i=0;i<n;i++){
            for(int j = n-1 ; j >= i ; j--){
                if(isPalindrome(s,i,j)){
                    if(j - i + 1 > longest.size()) {
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return longest;
    }
};