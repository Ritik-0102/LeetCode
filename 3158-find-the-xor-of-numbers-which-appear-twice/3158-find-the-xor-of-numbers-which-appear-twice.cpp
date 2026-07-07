class Solution {
public:
    int duplicateNumbersXOR(vector<int>& arr) {
        vector<int> freq(51 , 0);

        for(int i:arr){
            freq[i]++;
        }

        int ans = 0;
        for(int i=0 ;i<51 ;i++){
            if(freq[i] == 2){
                ans ^= i;
            }
        }

        return ans;
    }
};