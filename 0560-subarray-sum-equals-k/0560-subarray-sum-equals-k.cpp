class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1: we will find Prefix sum array
        vector<int> prefixSum(n);

        prefixSum[0] = arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        // Step 2: we know that subarraySum of range i to j index = prefix[j] - prefix[i]
        // so we will store the freq of prefix sum in map ,so that we can find subarray having sum = k , for every i'th element
        unordered_map<int,int> m;
        int count = 0;
        for(int i=0;i<n;i++){
            if(prefixSum[i] == k){
                count++;
            }
            if(m.find(prefixSum[i] - k) != m.end()){
                count += m[prefixSum[i] - k];
            }

            if(m.find(prefixSum[i]) != m.end()){
                m[prefixSum[i]]++;
            }
            else{
                m[prefixSum[i]] = 1;
            }
        }

        return count;
    }
};