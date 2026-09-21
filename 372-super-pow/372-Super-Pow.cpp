class Solution {
public:
// Instead of multiplying 2 ten times: Binary Exponentiation function
// 2^10
// = (2^5)^2
// = ((2^2) × 2)^2
    long long modPow(long long a,long long b,long long MOD){
        long long ans = 1;

        a %= MOD;
        while(b > 0){
            if(b & 1){
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long res = 1;
        const int MOD = 1337;

        for(int i:b){
            // res = ((res ^ 10) * (a ^ i)) % 1337
            long long part1 = modPow(res,10,MOD);
            long long part2 = modPow(a,i,MOD);

            res = (part1 * part2) % MOD;
        }

        return res;
    }
};