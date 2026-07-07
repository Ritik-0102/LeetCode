class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }

        // we will keep on dividing our number 
        while(n%3 == 0){
            n /= 3;
        }

        // if at last our number become 1 , then it is power of 3
        return n==1;
    }
};