class Solution {
public:
    int countPrimes(int n) {
        // By applying Sieve of Eratosthenes
        // First we suppose that all numbers are prime
        bool prime[n+1];
        memset(prime,true,n+1);

        for(int i=2; (i*i) < n ; i++){
            if(prime[i]){
                // Multiples of i should be marked false now
                for(int j = (i*i) ; j < n ; j += i){
                    prime[j] = false;
                }
            }
        }

        int ans = 0;

        for(int i=2;i<n;i++){
            if(prime[i]){
                ans++;
            }
        }

        return ans;
    }
};