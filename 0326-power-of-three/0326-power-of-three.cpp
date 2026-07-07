class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){ // 3^0 == 1
            return true;
        }

        if(n<3){
            return false;
        }
        
        while(n >= 0){
            if(n==3){
                cout << n;
                return true;
            }
            if(n%3 != 0){
                return false;
            }
            n/=3;
        }

        return false;
    }
};