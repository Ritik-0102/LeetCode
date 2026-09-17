class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        // Applying Seive of Eratosthenes - to find prime numbers

        vector<int> prime(n+1,1);
        prime[0] = 0;
        prime[1] = 0;

        for(int i=2; (i*i) < n ; i++){
            if(prime[i]){
                for(int j = (i*i) ; j < n ; j += i){
                    prime[j] = 0;
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<=n/2;i++){
            if(prime[i] == 1 && prime[n-i] == 1){
                ans.push_back({i,n-i});
            }
        }

        return ans;
    }
};