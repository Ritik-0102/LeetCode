class Solution {
public:
    int CountSetBits(int n){
        int SetBits = 0;

        while(n > 0){
            if(n & 1){
                SetBits++;
            }
            n >>= 1;
        }

        return SetBits;
    }

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

    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for(int i=left;i<=right;i++){
            if(isPrime(CountSetBits(i))){
                ans++;
            }
        }

        return ans;
    }
};