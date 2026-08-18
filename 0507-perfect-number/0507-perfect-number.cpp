class Solution {
public:
    bool checkPerfectNumber(int n) {
        // Base Case
        if(n <= 1){
            return false;
        }

        // 1 is divisor for all the numbers
        int sum = 1;
        for(int i=2 ; i*i <= n ; i++){
            // Golden Rule : Factors always comes in pairs 
            // i & n/i
            if(n % i == 0){
                sum += i;
                // if number is perfect square like 36 , so we just add 6 
                if(i*i != n){
                    sum += (n/i);
                }
            }
            if(sum > n){
                return false;
            }
        }

        return sum == n;
    }
};