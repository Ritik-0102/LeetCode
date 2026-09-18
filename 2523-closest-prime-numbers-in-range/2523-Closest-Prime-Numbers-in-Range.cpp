class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Applying Sieve of Eratosthenes
        vector<bool> isPrime(right + 1,true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2; (i*i) <= right ; i++){
            if(isPrime[i]){
                for(int j = (i*i) ; j <= right ; j += i){
                    isPrime[j] = false;
                }
            }
        }

        // Store All Prime numbers in the range(left,right)
        vector<int> primes;
        for(int i=left ; i <= right ; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }

        // Find minimum Pair
        vector<int> ans(2,-1);
        int minDiff = INT_MAX;

        for(int i = 1; i < primes.size(); i++){
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff){
                minDiff = diff;
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }
        }

        return ans;
    }
};