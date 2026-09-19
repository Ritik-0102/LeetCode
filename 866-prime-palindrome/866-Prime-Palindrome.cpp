class Solution {
public:
    bool isPrime(int n){
        if(n < 2){
            return false;
        }
        if(n % 2 == 0){
            return n == 2;
        }

        for(int i=3; (i*i) <= n ; i += 2){
            if(n % i == 0){
                return false;
            }
        }

        return true;
    }

    int MakeOddLengthPalindrome(int root){
        int Palindrome = root;

        root /= 10;
        while(root > 0){
            Palindrome = (Palindrome * 10) + (root % 10);
            root /= 10;
        }

        return Palindrome;
    }

    int primePalindrome(int n) {
        // Exception: The mathematical "Rule of 11" states that every even-length 
        // palindrome is divisible by 11. Therefore, 11 is the ONLY even-length 
        // palindrome that is also a prime number. 
        // If n is between 8 and 11, the first prime palindrome we will hit is 11. 
        if(n >= 8 && n <= 11){
            return 11;
        }

        // We only generate odd-length palindromes to skip the massive number of 
        // useless even-length palindromes.
        // A root up to 100,000 (5 digits) will generate a 9-digit palindrome.
        // Since the maximum constraint for N is 10^8 (8 digits), a 9-digit max is plenty.
        for(int root = 1 ; root <= 100000 ; root++){
            int Palindrome = MakeOddLengthPalindrome(root);

            if(Palindrome >= n && isPrime(Palindrome)){
                return Palindrome;
            }
        }

        return -1;
    }
};