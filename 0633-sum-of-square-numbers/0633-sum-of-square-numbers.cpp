class Solution {
public:
    bool judgeSquareSum(int c) {
        long i=0;
        long j=sqrt(c);

        while(i<=j){
            long long currSum = i*i + j*j;
            if(currSum == c){
                return true;
            }
            else if(currSum < c){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
};