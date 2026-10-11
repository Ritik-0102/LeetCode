class Solution {
public:
    int MergeSort(vector<int>& arr,vector<int>& temp,int left,int right){
        if(left >= right){
            return 0;
        }

        int mid = left + (right - left)/2;

        // Calculate Count of reverse pairs for left & right half
        int count = MergeSort(arr,temp,left,mid) + MergeSort(arr,temp,mid+1,right);

        // --- COUNTING CROSS-PAIRS ---
        // Pointer 'j' starts at the beginning of the right, already-sorted half.
        int j = mid + 1;

        // Iterate through each element of the left, already-sorted half.
        for(int i=left ; i <= mid ; i++){
            // Check the reverse pair condition: nums[i] > 2 * nums[j]
            // Because the right half is sorted, we can safely advance 'j' until the condition fails.
            while(j <= right && arr[i] > 2LL * arr[j]){
                j++;
            }
            
            // All elements in the right half from index (mid + 1) up to (j - 1) are valid reverse pairs for the current nums[i].
            count += (j - (mid + 1));
        }

        // Merge Step
        int i = left;
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

        // Copy back sorted elements to original array
        for(int x = left ; x <= right ; x++){
            arr[x] = temp[x];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        // To store temp array at every Merge step Merge Sort
        vector<int> temp(nums.size());

        return MergeSort(nums,temp,0,nums.size()-1);
    }
};