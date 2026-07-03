class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int pivot = -1;
        
        // Step 1: we will find the element which is in increasing order
        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                pivot=i;
                break;
            }
        }

        // If our array is in decreasing order
        if(pivot == -1){
            reverse(arr.begin(),arr.end());
            return;
        }

        // step 2: we will find element which is just greater than our pivot & swap with it
        for(int i=n-1;i>pivot;i--){
            if(arr[i]>arr[pivot]){
                swap(arr[pivot],arr[i]);
                break;
            }
        }

        // Step 3: now we need to reverse the elements , which are in decreasing order
        reverse(arr.begin() + pivot + 1,arr.end());
    }
};