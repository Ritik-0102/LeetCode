class Solution {
public:
    // we solve this problem using Prefix Sum + Merge Sort + Sliding Window
    int MergeSort(vector<long long>& arr,vector<long long>& temp,int left,int right,int lower,int upper){
        if(left >= right){
            return 0;
        }

        int mid = left + (right - left)/2;

        // Find count for Both the halfs
        int count = MergeSort(arr,temp,left,mid,lower,upper) + 
                    MergeSort(arr,temp,mid+1,right,lower,upper);

        // COUNT CROSS-PAIRS :- (The "Sliding Window" part)
        int i = mid + 1;
        int j = mid + 1;

        for(int k = left ;k <= mid ; k++){
            // Find the starting of the window
            while(i <= right && arr[i] - arr[k] < lower){
                i++;
            }

            // Find the ending of the window
            while(j <= right && arr[j] - arr[k] <= upper){
                j++;
            }

            count += (j - i);
        }

        // Merge Step
        i = left;
        j = mid + 1;
        int k = left;

        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= right){
            temp[k++] = arr[j++];
        }

        // Copy Back sorted elements to original array
        for(int x = left ; x <= right ; x++){
            arr[x] = temp[x];
        }

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n+1,0);

        for(int i = 0 ; i < n ; i++){
            prefix[i+1] = nums[i] + prefix[i];
        }

        vector<long long> temp(n+1);

        // Apply Merge Sort on Prefix Sum Array
        // The problem asks us to find pairs where:
        // lower <= (RightElement - LeftElement) <= upper

        // If we move LeftElement to the other sides of the inequality, we get:
        // LeftElement + lower <= RightElement <= LeftElement + upper

        // This tells us exactly what we are looking for: for every number in the left half, we need to find a "window" of valid numbers in the right half.
        return MergeSort(prefix,temp,0,n,lower,upper);
    }
};