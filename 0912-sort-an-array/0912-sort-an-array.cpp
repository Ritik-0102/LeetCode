class Solution {
public:
    void Merge(vector<int>& arr,int start,int mid,int end,vector<int>& temp){
        int i=start;
        int j=mid+1;
        int k=start; // pointer for temp array

        while(i<= mid && j<=end){
            if(arr[i]<arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        while(i<= mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }

        // Put back the sorted elements into main arr
        for(int i=start;i<=end;i++){
            arr[i] = temp[i];
        }
    }

    void MergeSort(vector<int>& arr,int start,int end,vector<int>& temp){
        if(start < end){
            int mid = start + (end - start)/2;

            MergeSort(arr,start,mid,temp);
            MergeSort(arr,mid+1,end,temp);

            Merge(arr,start,mid,end,temp);
        }
    }
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);

        MergeSort(arr,0,n-1,temp);

        return arr;
    }
};