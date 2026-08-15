class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int first = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        start = 0;
        end = arr.size() - 1;
        int second = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                second = mid;
                start = mid + 1;
            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return {first,second};
    }
};