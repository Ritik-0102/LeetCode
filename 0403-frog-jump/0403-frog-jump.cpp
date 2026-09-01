class Solution {
public:
    bool helper(int idx,vector<int>& stones,int k,unordered_map<int,int>& m,vector<vector<int>>& dp){
        if(idx == stones.size() - 1){
            return true;
        }

        // if we already know this
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int nextSteps[] = {k-1,k,k+1};

        for(int nextStep:nextSteps){
            // we can only move forward
            if(nextStep > 0){
                int nextStone = stones[idx] + nextStep;

                // if nextStone is present
                if(m.find(nextStone) != m.end()){
                    if(helper(m[nextStone],stones,nextStep,m,dp)){
                        dp[idx][k] = 1;
                        return true;
                    }
                }
            }
        }

        dp[idx][k] = 0;

        return false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[1] != 1){
            return false;
        }

        // store element with its index
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            m[stones[i]] = i;
        }

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return helper(1,stones,1,m,dp);
    }
};