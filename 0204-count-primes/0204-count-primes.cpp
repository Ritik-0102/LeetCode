class Solution {
public:
    int countPrimes(int n) {
        // By applying Sieve of Eratosthenes
        // First we suppose that all numbers are prime
        vector<bool> prime(n+1,true);

        int count_prime = 0;

        for(int i=2;i<n;i++){
            if(prime[i]){
                count_prime++;

                // Multiples of i should be marked false now
                for(long long j = (long long)i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return count_prime;
    }
};