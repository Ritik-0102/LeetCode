class Solution {
public:
    int findClosestNumber(vector<int>& arr) {
        int ans = arr[0];

        for(int i:arr){
            if(abs(i) < abs(ans)){
                ans = i;
            }
            else if(abs(i) == abs(ans) && i > ans){
                ans = i;
            }
        }

        return ans;
    }
};