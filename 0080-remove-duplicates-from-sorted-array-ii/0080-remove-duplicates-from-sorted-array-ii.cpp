class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        bool isPreviousSame = false;
        int i = 1;

        while(i < arr.size()){
            if(isPreviousSame && arr[i-1]==arr[i]){
                arr.erase(arr.begin() + i);
            }
            else if(arr[i-1]==arr[i]){
                isPreviousSame = true;
                i++;
            }
            else{
                isPreviousSame = false;
                i++;
            }
        }

        return arr.size();
    }
};