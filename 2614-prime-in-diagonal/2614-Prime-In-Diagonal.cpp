class Solution {
public:
    bool isPrime(int n){
        if(n < 2){
            return false;
        }
        if(n == 2 || n == 3){
            return true;
        }

        if(n % 2 == 0 || n % 3 == 0){
            return false;
        }

        for(int i=5;(i*i)<=n;i += 2){
            if(n % i == 0){
                return false;
            }
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            // Only check primality if it's strictly greater than our current max
            if(nums[i][i] > ans && isPrime(nums[i][i])){
                ans = max(ans,nums[i][i]);
            }
            if(nums[i][n - i - 1] > ans && isPrime(nums[i][n - i - 1])){
                ans = max(ans,nums[i][n - i - 1]);
            }
        }

        return ans;
    }
};