class Solution {
public:
    void MergeSort(vector<pair<int,int>>& arr,int left,int right,vector<pair<int,int>>& temp,vector<int>& res){
        if(left >= right){
            return;
        }

        int mid = left + (right - left)/2;

        MergeSort(arr,left,mid,temp,res);
        MergeSort(arr,mid+1,right,temp,res);

        // Merge Step
        int i = left;
        int j = mid + 1;
        int k = left;
        int rightCount = 0;

        while(i <= mid && j <= right){
            // if any element is smaller in right half than the elements in the left half
            // then we increament rightCount
            if(arr[j].first < arr[i].first){
                rightCount++;
                temp[k++] = arr[j++];
            }
            // Now add this rightCount for our left half elements
            else{
                res[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            }
        }

        // Process left half remaining elements
        while(i <= mid){
            res[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        }
        // Process right half remaining elements
        while(j <= right){
            temp[k++] = arr[j++];
        }

        // Copy back sorted elements to main array
        for(int p = left ; p <= right ; p++){
            arr[p] = temp[p];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        // Stores value with its idx
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i],i};
        }

        vector<pair<int,int>> temp(n);

        MergeSort(arr,0,n-1,temp,res);

        return res;
    }
};