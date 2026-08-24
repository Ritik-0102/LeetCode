class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maximumElem = INT_MIN;

        for(int i:nums){
            if(i > maximumElem){
                maximumElem = i;
            }
        }

        int ans = 0;
        for(int i = 0; i<k ; i++){
            ans += maximumElem;
            maximumElem += 1;
        }

        return ans;
    }
};