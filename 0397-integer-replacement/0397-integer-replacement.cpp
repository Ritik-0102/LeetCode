class Solution {
public:
    // we will just 
    unordered_map<long long,int> dp;

    int helper(long long n){
        if(n <= 1){
            return 0;
        }

        // if we already calculated it
        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        if(n % 2 == 0){
            // 1 step for division + helper(n/2)
            dp[n] = 1 + helper(n/2);
        }
        else{
            // 1 step for either (n-1) OR (n+1)  +  min(helper(n-1),helper(n+1));
            dp[n] = 1 + min(helper(n-1),helper(n+1));
        }

        return dp[n];
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};