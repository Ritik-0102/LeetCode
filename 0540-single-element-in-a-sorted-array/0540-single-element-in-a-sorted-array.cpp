class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return arr[0];
        }

        // Pre-check the boundaries so we never go out of bounds in the loop
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        int left = 1;
        int right = n - 2;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
                return arr[mid];
            }
            // If the elements on the left & right are even 
            if(mid%2 == 0){
                if(arr[mid-1]==arr[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            // If the elements on the left & right are odd
            else{
                if(arr[mid-1]==arr[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};