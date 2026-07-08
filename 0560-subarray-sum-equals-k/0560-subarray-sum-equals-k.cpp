class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1: we will find Prefix sum 

        // Step 2: we know that subarraySum of range i to j index = prefix[j] - prefix[i]
        // so we will store the freq of prefix sum in map ,so that we can find subarray having sum = k , for every i'th element
        unordered_map<int,int> m;

        int count = 0;
        int currSum = 0; // Running Prefix Sum

        for(int i=0;i<n;i++){
            currSum += arr[i];
            if(currSum == k){
                count++;
            }
            if(m.find(currSum - k) != m.end()){
                count += m[currSum - k];
            }

            m[currSum]++;
        }

        return count;
    }
};