class Solution {
public:
    double helper(double x,long long n) {
        if(x==1 || n==0){
            return 1.0;
        }
        if(n==1 || x==0){
            return x;
        }

        double half_power = helper(x,n/2);

        if(n % 2 == 0){
            return half_power * half_power;
        }
        else{
            return x * half_power * half_power;
        }
    }

    double myPow(double x, int n) {
        long long N=n;

        if(n<0){
            return 1.0 / helper(x,-N);
        }
        return helper(x,N);
    }

};