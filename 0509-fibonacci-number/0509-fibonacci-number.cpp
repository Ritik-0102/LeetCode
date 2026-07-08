class Solution {
public:
    int fib(int n) {
        if(n==1){
            return 1;
        }
        int sum = 0;

        int prev2=0;
        int prev1=1;

        for(int i= 1;i<n;i++){
            sum = prev1 + prev2;
            int temp = prev2 + prev1;
            prev2 = prev1;
            prev1 = temp;
        }

        return sum;
    }
};