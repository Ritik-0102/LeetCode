class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1,0);

        vector<int> ans;

        for(int i:arr){
            freq[i]++;
            if(freq[i] == 2){
                ans.push_back(i);
            }
        }

        return ans;
    }
};