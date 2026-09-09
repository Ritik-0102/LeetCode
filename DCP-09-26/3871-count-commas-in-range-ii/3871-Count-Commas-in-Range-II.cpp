class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long temp = 1000;

        while(temp <= n){
            commas += (n - temp + 1);
            temp *= 1000;
        }

        return commas;
    }
};