class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1; (i*i) < n ; i++){
            if(n % i == 0){
                k--;
            }

            if(k == 0){
                return i;
            }
        }

        // If kth Factor exists in Factors greater than Sqrt(n)
        for(int i = sqrt(n) ; i > 0 ; i--){
            if(n % i == 0){
                k--;
            }

            if(k == 0){
                return n / i;
            }
        }

        return -1;
    }
};