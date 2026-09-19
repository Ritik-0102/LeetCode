class Solution {
public:
    int reverse(int n){
        int ans = 0;
        while(n > 0){
            ans = (ans * 10) + (n % 10);
            n /= 10;
        }

        return ans;
    }

    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);

        int left = min(n,rev);
        int right = max(n,rev);

        // Applying Sieve of Eratosthenes
        vector<bool> prime(1005,true);
        prime[0] = false;
        prime[1] = false;

        for(int i=2;(i*i) <= 1005 ; i++){
            if(prime[i]){
                for(int j = (i*i) ; j < 1005 ; j += i){
                    prime[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i=left ; i <= right ; i++){
            if(prime[i]){
                ans += i;
            }
        }

        return ans;
    }
};