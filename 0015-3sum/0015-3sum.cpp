class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int n = arr.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            // To avoid duplicate triplets
            while(i>0 && i<n && arr[i] == arr[i-1]){
                i++;
            }

            int j=i+1;
            int k=n-1;

            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;

                    // To avoid duplicate triplets
                    while(j<k && arr[j] == arr[j-1]){
                        j++;
                    }
                }
                else if(sum < 0){
                    // we need to increase our sum
                    j++;
                }
                else if(sum > 0){
                    // we need to decrease our sum
                    k--;
                }
            }
        }

        return ans;
    }
};