class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }

        int ans = 0;

        // If any one is negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long Dividend = llabs(dividend);
        long long Divisor = llabs(divisor);

        while(Dividend >= Divisor){
            long long tempDivisor = Divisor;
            long long multiple = 1;

            while(Dividend >= (tempDivisor << 1)){
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            Dividend -= tempDivisor;
            ans += multiple;
        }

        return isNegative ? -ans : ans;
    }
};