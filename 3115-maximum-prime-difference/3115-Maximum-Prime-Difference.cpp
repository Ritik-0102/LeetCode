class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        // Applying Seive of Eratosthenes
        vector<bool> prime(105,true);
        prime[0] = false;
        prime[1] = false;

        for(int i=2;(i*i) <= 105 ; i++){
            if(prime[i]){
                for(int j = (i*i) ; j <= 105 ; j += i){
                    prime[j] = false;
                }
            }
        }

        int first = -1;
        for(int i=0;i<nums.size();i++){
            if(prime[nums[i]]){
                first = i;
                break;
            }
        }

        int second = -1;
        for(int i=nums.size()-1 ; i>=0 ;i--){
            if(prime[nums[i]]){
                second = i;
                break;
            }
        }

        return second - first;
    }
};