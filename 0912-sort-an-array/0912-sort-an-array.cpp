class Solution {
public:
    void Merge(vector<int>& arr,int start,int mid,int end){
        int i=start;
        int j=mid+1;

        vector<int> temp;
        while(i<= mid && j<=end){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }

        int n = temp.size();
        for(int i=0;i<n;i++){
            arr[i+start] = temp[i];
        }
    }

    void MergeSort(vector<int>& arr,int start,int end){
        if(start < end){
            int mid = start + (end - start)/2;

            MergeSort(arr,start,mid);
            MergeSort(arr,mid+1,end);

            Merge(arr,start,mid,end);
        }
    }
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();

        MergeSort(arr,0,n-1);

        return arr;
    }
};