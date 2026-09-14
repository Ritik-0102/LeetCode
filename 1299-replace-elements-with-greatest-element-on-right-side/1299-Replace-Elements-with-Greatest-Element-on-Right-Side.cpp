class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maximum = -1;
        int temp = -1;

        for(int i=arr.size()-1;i>=0;i--){
            temp = maximum;
            maximum = max(arr[i],maximum);
            arr[i] = temp;
        }

        return arr;
    }
};