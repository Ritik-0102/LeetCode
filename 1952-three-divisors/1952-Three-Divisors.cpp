class Solution {
public:
    // The number which has exactly three Divisors - It is Square Of Prime Number

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

        for(int i=5; i*i <= n ; i++){
            if(n % i == 0){
                return false;
            }
        }

        return true;
    }
    
    bool isThree(int n) {
        int root = sqrt(n);

        if(root * root != n){
            return false;
        }

        return isPrime(root);
    }
};