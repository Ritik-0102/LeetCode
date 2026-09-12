class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> freqIdx;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == x){
                freqIdx.push_back(i);
            }
        }

        vector<int> ans(queries.size(),-1);

        for(int i=0;i<queries.size();i++){
            if(queries[i] <= freqIdx.size()){
                ans[i] = freqIdx[queries[i] - 1];
            }
        }

        return ans;
    }
};