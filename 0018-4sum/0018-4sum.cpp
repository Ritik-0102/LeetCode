class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        // We need to sort the array to handle the duplicates
        sort(arr.begin(),arr.end());

        vector<vector<int>> ans;

        int n = arr.size();

        for(int i=0;i<n-3;i++){
            // Handle duplicate values for i
            if(i > 0 && arr[i]==arr[i-1]){
                continue;
            }

            for(int j = i+1 ; j<n-2;j++){     
                // Handle duplicate values for j
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;           
                int p = j+1;
                int q = n-1;

                while(p<q){
                    long long quadrupletSum = (long long)arr[i] + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];

                    if(quadrupletSum == target){
                        ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                        p++;
                        q--;

                        // To Handle Duplicate values
                        while(p < n && arr[p]==arr[p-1]){
                            p++;
                        }
                    } 
                    else if(quadrupletSum < target){
                        p++;
                    }
                    else{
                        q--;
                    }
                }
            }
        }

        return ans;
    }
};